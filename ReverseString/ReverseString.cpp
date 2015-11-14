#include <stdio.h>
#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////


int main()
{

  string testString = "Applesauce";

  for (int i = testString.size()-1; i >= 0; i--)
  {
    cout << testString[i];
  }

  return 0;
}
////////////////////////////////////////////////////////////////////////////////
