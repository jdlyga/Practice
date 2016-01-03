#include <iostream>
#include "infint.h"

using namespace std;

InfInt calculateSteps(int totalSteps)
{
  InfInt nMinus1 = 4;
  InfInt nMinus2 = 2;
  InfInt nMinus3 = 1;
  InfInt n = -1;

  if (totalSteps == 0) return 0;
  if (totalSteps == 1) return nMinus3;
  if (totalSteps == 2) return nMinus2;
  if (totalSteps == 3) return nMinus1;

  for (int i = 4; i <= totalSteps; i++)
  {
    n = nMinus3 + nMinus2 + nMinus1;
    nMinus3 = nMinus2;
    nMinus2 = nMinus1;
    nMinus1 = n;
  }

  return n; 
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  cout << "Number of ways a child can reach a height by skipping 1, 2, or 3 steps...\n";
  for (int i = 0; i <= 100; i++)
  {
    cout << "Height " << i << ": " << calculateSteps(i) << endl;
  }
}
