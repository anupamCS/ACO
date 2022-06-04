#pragma once
#include<iostream>
#include "Rand.h"
using namespace std;

//Choosing Best Next
void ChooseBestNext(sant &q,int i,int n,double **choice_info)
{
    double v=0.0;
    int c=q.tour[i-1],t=0;
    for(int j=0;j<n;j++)
    {
            if(q.visited[j]==false)
            {
                if(choice_info[c][j]>v)
                {
                      t=j;  // vertex (city) with max (tao[i][j]^alpha)*(ita[i][j]^beta)
                      v=choice_info[c][j];
                }
            }
    }

    q.tour[i]=t;
    q.visited[t]=true;
    
}

//Neighbor List Decision Rule
void NeighborListDR(sant &q,int n,int i,double **choice_info,int **nn_list)
{
     int c=q.tour[i-1];
     double sum_prob=0.0,selec_prob[n+1];
     for(int j=0;j<n;j++) // n means nn (depth)
     {
         if(i != j)  //my entry check
         {
           if(q.visited[nn_list[c][j]] == true)
                 selec_prob[j]=0.0;
           else
            {
                selec_prob[j]=choice_info[c][nn_list[c][j]];
                sum_prob += selec_prob[j];
            }
         }
     }
     if(sum_prob==0.0)
      {
        // cout<<endl<<"chosing best next"<<endl;
         ChooseBestNext(q,i,n,choice_info);
      }
     else
     {
         float r=randomfloat(sum_prob); // random no b/w [0,sum_probability]
         int g=0; 
         float p=selec_prob[g];
         while(p<r)
         {
            g++;
            p+=selec_prob[g];
         }
         q.tour[i]=nn_list[c][g];
         q.visited[nn_list[c][g]]=true;
     }

}
