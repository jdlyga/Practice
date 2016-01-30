#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

/*

  M1 = smallest
  M2 = next smallest
  L = left index
  R = right index
  
  9 xor 6
*/


int main() 
{
  int length;
  cin >> length;
  
  vector<int> a(length);
  
  for (int i = 0; i < length; i++)
  {
    cin >> a[i]; 
  }
  
  int maxPossibleVal = std::numeric_limits<int>::lowest();
  int li = 0;
  int ri = 1;
  
  while(li < length-1)
  {
    int min1 = std::numeric_limits<int>::max();
    int min2 = min1;
    
    //find 2 min in range
    for (int i = li; i <= ri; i++)
    {
      if (a[i] < min1)
      {
        min2 = min1;
        min1 = a[i];
      }
      else if (a[i] < min2)
      {
        min2 = a[i];
      }
    }
  
    if ((min1 ^ min2) > maxPossibleVal)
    {
      maxPossibleVal = min1 ^ min2;
      //cout << "min1: " << min1 << " min2: " << min2 << " li: " << li << " ri: " << ri << " max: " << maxPossibleVal << endl;
    }
      
    ri++;
    if (ri >= length)
    {
      li++;
      ri = li+1;
    }
  }
  
  cout << maxPossibleVal;
  
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  return 0;
}
