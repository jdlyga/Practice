#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

int getNumReplacements(string & a, string & b)
{   
    int minL = a.length() < b.length() ? a.length() : b.length();
    
    int numReplacements = 0;

    for (int i = 0; i < minL; i++)
    {
        if (a[i] != b[i])
            numReplacements++;
    }
    
    return numReplacements;
}    
    
bool testCharInsert(string & strl, string & strr)
{
    int li = 0, ri = 0;
    
    while (li < strl.length() && ri < strr.length())
    {
        if (strl[li] != strr[ri])
        {
            if (li != ri)
                return false;
            
            ri++;
        }
        else
        {
            li++;
            ri++;
        }
    }
    return true;
}


bool isOneAway(string & a, string & b)
{
    if (abs(a.length() - b.length()) > 1)
        return false;
        
    if (a.length() == b.length())
    {
        if (getNumReplacements(a, b) > 1)
            return false;
    }
    else
    {
        if (a.length() < b.length())
            return testCharInsert(a,b);
        else
            return testCharInsert(b,a);
    }

    return true;
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  string s1a = "pale", s1b = "ple";
  string s2a = "pales", s2b = "pale";
  string s3a = "pale", s3b = "bale";
  string s4a = "pale", s4b = "bake";
  string s5a = "apples", s5b = "bananas";

  cout << isOneAway(s1a, s1b) << endl;
  cout << isOneAway(s2a, s2b) << endl;
  cout << isOneAway(s3a, s3b) << endl;
  cout << isOneAway(s4a, s4b) << endl;
  cout << isOneAway(s5a, s5b) << endl;
  
  return 0;
}
