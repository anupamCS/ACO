#pragma once
static int flag=0; // for allowing, first time of each ant
  
/*-----------Update Local Best for each ant-----------*/
void UpdateLocal(sant *ants,int m)
{
   
     for(int i=0;i<m;i++)
     {
         if(((ants[i].best_soltn.best_tour_len) > (ants[i].tour_length)) || (::flag==0)) /*'0' is checked for initialization of best_solutn*/
          {
               ants[i].best_soltn.best_tour_len = ants[i].tour_length;
               for(int w=0;w<=m;w++)
               {
                      ants[i].best_soltn.best_tour[w]= ants[i].tour[w];
               }                                     
          }
     }
     ::flag++;
}

/*-----Worst Tour Length-------*/
void UpdateMAX(sant *ants,int m)
{
   
     for(int i=0;i<m;i++)
     {
         if(((ants[i].best_soltn.best_tour_len) < (ants[i].tour_length)) || (::flag==0)) /*'0' is checked for initialization of best_solutn*/
          {
               ants[i].best_soltn.worst_tour_len = ants[i].tour_length;
               for(int w=0;w<=m;w++)
               {
                      ants[i].best_soltn.worst_tour[w]= ants[i].tour[w];
               }                                     
          }
     }
     ::flag++;
}

/*-------Find the Global Optimal Solution-----------*/
int FindGlobalBest(sant *ants,int m)
{
    int best_ant=0,temp_tour_length=ants[0].best_soltn.best_tour_len;
    cout<<"\n\nBest Tour Lengths: \n"<<endl;
    for(int index=0;index<m;index++)
    {
          cout<<"ant["<<index<<"] best tour length: "<<ants[index].best_soltn.best_tour_len;
          cout<<"\n\n";              
    }   
    for(int i=0;i<m;i++)
    {

          if(ants[i].best_soltn.best_tour_len < temp_tour_length)
             {
                 best_ant=i;
                 temp_tour_length=ants[i].best_soltn.best_tour_len;
             }
              
    }   
    cout<<"\n\nTHE BEST ANT:"<<best_ant<<endl<<endl;
    return best_ant; 
}
