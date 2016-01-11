#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> v = {0, 0, 0, 0, 
                   0, 0, 0, 1, 
                   0, 0, 1, 0,
                   0, 0, 1, 1, 
                   0, 1, 0, 0, 
                   0, 1, 0, 1, 
                   0, 1, 1, 1, 
                   1, 0, 0, 0};
  int n = 8;

  const int NUMBITS = 4;

  int numCounter = -1;
  bool bitVal = false;
  for (int i = NUMBITS-1; i < n*NUMBITS; i += NUMBITS)
  {
    numCounter++;
    if (v[i] == bitVal)
    {
      bitVal = !bitVal;
    }
    else
    {
      cout << "Missing number is: " << numCounter << endl;
      break;
    }
  }
}
