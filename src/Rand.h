#include<iostream>
#include<time.h>
using namespace std;


/*-----random floating point no generation-----------*/
 
 double randomfloat(double ub)
  {

      srand(time(NULL));
      double q=((float)rand()/(float)RAND_MAX)*ub;
      return q;
  }
