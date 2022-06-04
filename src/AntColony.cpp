/*
=======================================================================================
=======================================================================================
IMPLEMENTING ACO(ANT COLONY OPTIMIZATION) FOR TSP(TRAVELING SALESMAN PROBLEM)
AS [vividly ANTI CYCLE] TECHNIQUE IS USED
***************************************************************************************
INPUT FILE: "Data.txt"
OUTPUT FILES: "Out.txt" -> containing the local best and the global best of each ant.
              "tour.txt" -> containing the list of all the tours of all ants.
              "Temp_matrices.txt" -> conataing the final modified pheromone matrix
                                     after all iterations for future modification
                                     and adjustments.
N.B: Infinity is defined as 9999, without the loss of genarality.
***************************************************************************************
By: Anupam Sarkar 
OS: Windows 7 (64 bit)
=======================================================================================
=======================================================================================
*/
#include <cstdlib>
#include <iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#include "TSP.h"
#include "timer.h"

#define alpha 1  // as per AS
#define beta 3   // since, AS allows to take a value b/w (2,5)

/*-------Max no of Iteration----------*/
#define MAX_ITERATION 10 // alter depending upon the necessity of your problem

using namespace std;

/*----terminating condition----------------*/
int terminating_condition(int i)
{
     return (i > MAX_ITERATION);
}

/*----- main program ----------------------------*/
int main()
{
    start_timer(); //start to compute CPU time
    double x;

    ACO colony;    //an ACO colony(object) of for solving TSP 
    colony.intialize_ACO();  //initialize all matrices

    system("pause");
    int iteration=1;
    while(!terminating_condition(iteration))
    {
        colony.construct_soltuion();

        colony.UpdateLocal();

        colony.PheromoneUpdate();

        iteration++;

        cout<<"\n\n\n                                               "<<iteration<<endl;

    }
    colony.writealldetails();

    x=elapsed_time();
    cout<<"\n\nELAPSED CPU TIME: "<<x<<" sec"<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}//End main( )
