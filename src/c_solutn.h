 #pragma once
 #include<iostream>
 #include<stdio.h>
 #include<time.h>
 #include<cstdlib>
 #include "ant.h"
 #include "NL_DR.h"

 using namespace std;
 void ASDecisionRule(sant &q,int i,int n,double **choice_info);
 void store_current_tour(sant ants[],int m);


 /*---------- Compute the tour length ------------*/
 int ComputeTourLength(sant &w,int **distance,int n)
 {

     int tourlen=0,c=w.tour[0],v=0;
     for(int j=0;j<n;j++)
     {
        // if((w.tour[j])!=(w.tour[j+1]))
         {
               v=distance[w.tour[j]][w.tour[j+1]];+distance[w.tour[j+1]][w.tour[j]]; //since either of distance[j+1][j] or [j][j+1] will be zero
               tourlen += v;
         }
     }
   //##  cout<<"\n\ntour length: "<<tourlen;
     return tourlen;
 }

 void construct_soltuion(sant ants[],int m,double **choice_info,int **nn_list,int **distance)
 {
      cout<<"\nant_solutn"<<endl;
      int n=m; // no of ants=no of vertices
      
      for(int k=0;k<m;k++)  //initialize the visited[] for each ant
      {
           ants[k].visited=new bool[m]; // default initialization constructor is not called
           for(int i=0;i<n;i++)
           {
              ants[k].visited[i]=false;
           }
      }
      cout<<endl;
      int step=0; // tracks the no of steps

      srand(time(NULL)); // to initialize rand(seed)
      int r;


      for(int k=0;k<m;k++)   //include the starting vertex for each ant
      {
         ants[k].tour=new int[n+1]; 
         r=rand()%m;      //nt rand()%(m-1),since vertex index ranges b/w [0,n]
   //##      cout<<"\n\nrandom no["<<k<<"]:"<<r<<endl;
         ants[k].tour[step]=r;
         ants[k].visited[r]=true;
      }
      int flg=1,tracker;
      while(step<(n-1))
      {
         step=step+1;
         cout<<"\n"<<flg++; // for tracing bug
         for(int k=0;k<m;k++)
         {

             if(step==1)
                ASDecisionRule(ants[k],step,n,choice_info);
             else
                NeighborListDR(ants[k],n,step,choice_info,nn_list);       // check
         }

      }
      for(int k=0;k<m;k++)
      {

          ants[k].tour[n]=(ants[k].tour[0]); // since,the ant returns to it's origin
          ants[k].tour_length=ComputeTourLength(ants[k],distance,n);
    //##  cout<<"\n\nants["<<k<<"].tour_length: "<<ants[k].tour_length<<endl<<endl;
      }
      // store the current tour of all the ants
      store_current_tour(ants,m);

 }

 void ASDecisionRule(sant &q,int i,int n,double **choice_info)
 {
      int c=q.tour[i-1];
      double sum_prob=0.0; //sum_probability calculating index
      double selec_p[n];   // contains temporary (tao[i][j]^alpha)*(ita[i][j]^beta) for each j
      float r; // random value from [0,sum_prob]
      for(int j=0;j<n;j++)
      {
          if(q.visited[j]==true)
              selec_p[j]=0.0;
          else
           {
              selec_p[j]=choice_info[i][j];
              sum_prob=sum_prob+selec_p[j];
           }

      }
      double w=sum_prob;
  //##    cout<<"\nsum_prob: "<<w<<endl;
      r=randomfloat(sum_prob);   // random no b/w [0,sum_probability]
      int g=0;
      float p=selec_p[g];
      while(p<r)
      {
         g++;
         p += selec_p[g];
      }
      q.tour[i]=g;
      q.visited[g]=true;


 }
 
 /*-----store the current tour in "tour.txt" at i'th iteration--------*/
void store_current_tour(sant ants[],int m)
{ 
     
     FILE *ft;
     ft=fopen("tour.txt","a+");

     if(ft==NULL)
     {
        puts("No more space in memory");
        fclose(ft);
        return;           // exit(int) is deliberately ignored
     }
     fprintf(ft,"\n\n\n"); // three new lines before print a tour of i'th iteration
     for(int k=0;k<m;k++)
     {
        for(int j=0;j<=m;j++)
            fprintf(ft,"%d-> ",ants[k].tour[j]);
         fprintf(ft,"\n");
        
     }

   //  fprintf(ft,"\nTour Length: %d",q.best_soltn.best_tour_len);
     fclose(ft);
    // ft=fopen("GlobalBest.txt","a+"); //a+ opens the file in append mode
     
}

