#include <stdio.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////


int main()
{
  vector<int> myVect = {1, 2, 3, 4, 5, 2, 5, 6, 7, 1, 10, 99, 2, 4, 5, 1, 5, 6};

  map<int, int> myMap;
  for (auto elem : myVect)
  {
    myMap[elem] += 1;
  }

  for (auto entry : myMap)
  {
    if (entry.second > 1)
    {
      cout << entry.first << " appears " << entry.second << " times" << endl;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
