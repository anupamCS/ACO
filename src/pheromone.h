#pragma once

#define alpha 1 // as in main.cpp
#define beta 3  // as in main.cpp

#define roe 0.5 //predefined in roe

/*----Evaporate----*/
void Evaporate(int m,float **pheromone)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            pheromone[i][j]=(1 - roe)*pheromone[i][j];
            pheromone[j][i]=pheromone[i][j]; //since,symmetric
        }
    }
}

void DepositPheromone(sant &q,int n,float **pheromone)
{
    int l=0,j=0;
    float del_t= 1/(float)q.tour_length;
   //## cout<<"\ndel_t:"<<del_t;
    for(int i=0;i<n;i++)
    {
        j=q.tour[i];
        l=q.tour[i+1];
        pheromone[j][l]+= del_t;
        pheromone[l][j]=pheromone[j][l];
    }

}

void ComputeChoiceInfo(float **pheromone,double **choice_info,int n,float **H)
{
    for(int i=0;i<n;i++)
                     {
                        for(int j=0;j<n;j++)
                           choice_info[i][j]=pow((double)pheromone[i][j],alpha)*pow((double)H[i][j],beta);
                     }
}

/*----pheromone update-----------------------*/
void PheromoneUpdate(sant *ants,int m,float **pheromone,double **choice_info,float **H)
{
    Evaporate(m,pheromone);
    for(int k=0;k<m;k++)
        DepositPheromone(ants[k],m,pheromone);

    ComputeChoiceInfo(pheromone,choice_info,m,H);
}
