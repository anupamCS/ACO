#pragma once
#include<stdlib.h>
#include<iostream>
#include<stdio.h>

#include "c_solutn.h"
#include "ant.h"
#include "Update_Find.h"
#include "pheromone.h"

#define alpha 1  // as per AS
#define beta 3   // since, AS allows to take a value b/w (2,5)

using namespace std;

/*------class Travelling Salesman Problem (TSP)--------*/
class TSP
{
protected:
    int **distance;
    int noa;  // no of cities/vertex
public:
    
    void input(int **&array,FILE *fp)
    {
        int i,j;
        int temp;
        for(int i=0;i<noa;i++)
        {
                for(int j=0;j<noa;j++)
                {
                    fscanf(fp,"%d",&temp);
                    if(i<=j)
                    {
                        array[i][j]=temp; //reading data from file
                        array[j][i]=array[i][j];
                    }
                }

        }
    }
    void intialize_TSP()
    {
        FILE *fp;
        fp=fopen("Data.txt","r");
        if(fp==NULL)
        {
                   cout<<"No File exists";
                   getch();
                   exit(0);
        }
        char line[500];        //buffer
        int count=0;
        while(fgets(line,sizeof(line),fp)!=NULL)
        {
            if(count==1)
            {
                sscanf(line,"%d",&noa);
                 distance=new int * [noa];
                 for(int i=0;i<noa;i++)
                    distance[i]=new int [noa];
            }
            if(count==2)   //distance and heuristics intitialization
            {
                    input(distance,fp);
                    count+=noa-1;
            }
            count++;
        }
        fclose(fp);
    }
    ~TSP()
    {
       for(int i=0;i<noa;i++)
          delete distance[i];
       delete distance;
    }
};// End class TSP

class ACO: public TSP
{
    int **nn_list; //Nearest Neighbour List
    float **pheromone;          //Pheromone Matrix
    float **H;                //Heuristics Matrix
    double **choice_info;
    sant *ants; // Array of m ants


public:
    /*-----sorting of nn_list,the nearest vertex(city) comes first------*/
    void sortlist(int *list,int row,int size)
    {
        int temp,r1,r2,c1,c2;
        for(int i=0;i<size;i++)
        {
                for(int j=0;j<size-i-1;j++)
                {
                        r1=r2=row;
                        c1=list[j];
                        c2=list[j+1];
                        if(r1>c1)
                        {
                            temp=r1;
                            r1=c1;
                            c1=temp;
                        }
                        if(r2>c2)
                        {
                            temp=r2;
                            r2=c2;
                            c2=temp;
                        }
                        if(distance[r1][c1]>distance[r2][c2])
                        {
                            temp=list[j];
                            list[j]=list[j+1];
                            list[j+1]=temp;
                        }
                }
        }
    }//end of sortlist()

    void intialize_ACO()
    {
        intialize_TSP();

        //creating ants
        ants=new sant [noa];
        for(int i=0;i<noa;i++)
           ants[i]=sant(noa);

        //initialize all the dependent matrices from distance matrix
        nn_list=new int * [noa];
        pheromone=new float * [noa];
        H=new float * [noa];
        choice_info=new double * [noa];
        for(int i=0;i<noa;i++)
        {
             nn_list[i]=new int [noa];
             pheromone[i]=new float [noa];
             H[i]=new float [noa];
             choice_info[i]=new double [noa];
        }
        //NN_LIST
        int k;
        for(int i=0;i<noa;i++)
        {
            k=0;
            for(int j=0;j<i;j++)
            {
                if(distance[j][i]!=-1)
                nn_list[i][k++]=j;
            }
            for(int j=i+1;j<noa;j++)
            {
                if(distance[i][j]!=-1)
                nn_list[i][k++]=j;
            }
            for(;k<noa;k++)
            nn_list[i][k]=i; // to represent it is connected to itself
            sortlist(nn_list[i],i,k);
        }
        //HEURISTICS
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
             {
                    if(i<=j&&distance[i][j] != -1)
                    {
                           H[i][j]=(float)1/(distance[i][j]+0.001); //0.001 ignoring negative value
                           H[j][i]=H[i][j]; 
                    }
             }
        }

        //PHEROMONE
        float nearest_neighbour_H=(float)round_trip();
        for(int i=0;i<noa;i++)
        {
            for(int j=0;j<noa;j++)
                pheromone[i][j]=(float)((float)noa/nearest_neighbour_H);

        }

        //CHOICE INFO
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
                choice_info[i][j]=(pow((double)pheromone[i][j],alpha)*pow((double)H[i][j],beta));
        }
        showall();
    }//end of intialize_ACO()

    void showall()
    {
        std::cout.precision(3); // setting the cout precision to 5 places
        cout<<endl<<"Distance:"<<std::fixed<<endl<<endl;
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
                     cout<<distance[i][j]<<" \t";
            cout<<"\n";
        }
        cout<<endl<<"Nearest Neighbour List:"<<endl<<endl;
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
                     cout<<nn_list[i][j]<<" \t";
            cout<<"\n";
        }
        cout<<endl<<"Heuristic Matrix:"<<endl<<endl;
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
                     cout<<H[i][j]<<" \t";
            cout<<"\n";
        }
        cout<<endl<<"Pheromone Matrix:"<<endl<<endl;
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
                     cout<<pheromone[i][j]<<" \t";
            cout<<"\n";
        }
        cout<<endl<<"Choice Info:"<<endl<<endl;
        for(int i=0;i<noa;i++)
        {
             for(int j=0;j<noa;j++)
                     cout<<choice_info[i][j]<<" \t";
            cout<<"\n";
        }
    }//end of showall()

    void construct_soltuion()
    {
        ::construct_soltuion(ants,noa,choice_info,nn_list,distance);
    }
    void UpdateLocal()
    {
        ::UpdateLocal(ants,noa);
    }
    void PheromoneUpdate()
    {
        ::PheromoneUpdate(ants,noa,pheromone,choice_info,H);
    }
    void UpdateMAX()
    {
        ::UpdateMAX(ants,noa); 
    }


/****************START OF STORING Data TO FILE*************/

/*-------Temporary matrices-------------*/
void store_temp_info(void)
{
     FILE *fz;
     fz=fopen("Temp_matrices.txt","w");
     if(fz==NULL)
     {
        puts("No more space in memory");
        fclose(fz);
        return;           // exit(int) is deliberately ignored
     }

           fprintf(fz,"\n------------------------------------------------------------------------\n");
           fprintf(fz,"Final Pheromone Matrix:\n");
           fprintf(fz,"\n------------------------------------------------------------------------\n");
           for(int x=0;x<noa;x++)
               {
                   for(int y=0;y<noa;y++)
                   {
                       fprintf(fz,"%f\t",pheromone[x][y]);
                   }
                   fprintf(fz,"\n");
               }

           fflush(fz); // flushing out the std o/p

           fprintf(fz,"\n");

     fprintf(fz,"------------------------------------------------------------------------");
     fprintf(fz,"\n------------------------------------------------------------------------\n");
     fclose(fz);

}



/*-------write to file---------*/
void write2file_op(sant *ants,int n)
{
     FILE *ft;
     ft=fopen("Out.txt","w");
     if(ft==NULL)
     {
        puts("No more space in memory");
        fclose(ft);
        return;           // exit(int) is deliberately ignored
     }
     fprintf(ft,"\nLocal Best Solution for Each Ant:\n");
     for(int i=0;i<n;i++)
     {
           fprintf(ft,"\n------------------------------------------\n");
           fprintf(ft,"%d ant\n",i);
           fprintf(ft,"Tour:  ");
           fflush(ft); // flushing out the std o/p
           for(int j=0;j<n+1;j++)
               fprintf(ft,"%d-> ",ants[i].best_soltn.best_tour[j]);
           fprintf(ft,"\nTour_length: %d",ants[i].best_soltn.best_tour_len);
           fprintf(ft,"\n");
     }
     fprintf(ft,"------------------------------------------\n------------------------------------------\nACO TSP IMPLEMENTED");
     fclose(ft);
}




/*----Store the BEST SOLUTION in file --------*/
void store_best_info(sant &q,int m)
{
    FILE *ft;
     ft=fopen("Out.txt","a+");

     if(ft==NULL)
     {
        puts("No more space in memory");
        fclose(ft);
        return;           // exit(int) is deliberately ignored
     }

     fprintf(ft,"\n\nGLOBAL BEST SOLUTION:\n");
     fprintf(ft,"\n\n------------------------------------------\n------------------------------------------\n\n\nTOUR:");
     for(int j=0;j<=m;j++)
          fprintf(ft,"%d-> ",q.best_soltn.best_tour[j]);

     fprintf(ft,"\nTour Length: %d",q.best_soltn.best_tour_len);
     fclose(ft);
     ft=fopen("GlobalBest.txt","a+"); //a+ opens the file in append mode


}/****************END OF STORING TO FILE*************/

void writealldetails()
{
    int best_ant= FindGlobalBest(ants,noa);
    store_temp_info();
    write2file_op(ants,noa);
    store_best_info(ants[best_ant],noa);
}//end of writealldetails()


    int round_trip()
    {
        cout<<"No of Cities = No of Ants = "<<noa<<endl;
        int cnt=1,w=0,rt=0,i,j=0,q; // rt holds the value of the nearest neighbour heuristic
        sant *temp;
        temp=new sant(noa);
        temp->tour[0]=0;
        temp->tour[noa]=0;
        temp->visited[0]=true;
        while(cnt <= noa-1)
           {

              for(i=0;temp->visited[nn_list[w][i]]==true && i<noa;i++);
              w=nn_list[w][i];
              temp->tour[++j]=w;
              temp->visited[w]=true;
              cnt++;
           }
        cout<<endl<<"Nearest Neighbour: \n";
        for(int z=0;z<=noa;z++)
          cout<<temp->tour[z]<<"->";
        rt=ComputeTourLength(*temp,distance,noa);
        cout<<"Minimum Tour length in greedy technique starting from node 0: "<<rt<<endl<<endl;
        return rt; // contains dummy parameter
    }
    
    ~ACO()
    {
        /*---destructing choice info----*/
         for(int i=0;i<noa;i++)
          delete choice_info[i];
       delete choice_info; 
       
       /*---destructing pheromone matrix----*/
       for(int i=0;i<noa;i++)
          delete pheromone[i];
       delete pheromone;
       
      /*---destructing Heuristics----*/ 
       for(int i=0;i<noa;i++)
          delete H[i];
       delete H;
    }
};//End class ACO
