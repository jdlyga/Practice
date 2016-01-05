#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
  int k = 3;
  deque<string> lastKLines;
  string line;
    
  while (getline(cin, line))
  {
    lastKLines.push_back(line);
    if (lastKLines.size() > k)
    {
      lastKLines.pop_front();
    }
  }  
    
  for (int i = 0; i < lastKLines.size(); i++)
  {
   cout << lastKLines[i] << endl;
  }
}
