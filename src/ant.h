#pragma once
#include<stdio.h>
//class single_ant
class sant
{
    public:
	int tour_length; // the ant's tour length
	int *tour;   // ant's partial tours
	bool *visited;  //visited cities
	struct bestsolfound{
           int best_tour_len;
           int *best_tour;
           int worst_tour_len; // ## extra
           int *worst_tour;    // ## extra
           }best_soltn;

	sant();
	sant(int n);
	~sant(void);

};// end class sant

sant::sant()
{}
sant::sant(int n)
{
	tour=new int[n+1]; ///////S
	visited=new bool [n];
	for(int i=0;i<n;i++)
		visited[i]=false;
	tour_length=0;   ///////E
	best_soltn.best_tour_len=0;
	best_soltn.best_tour= new int[n+1];
	best_soltn.worst_tour_len=0;
	best_soltn.worst_tour= new int[n+1];

}

sant::~sant(void)
{
}
