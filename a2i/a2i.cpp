#include <cstdio>
#include <string>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int a2i(const string & s)
{
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
  {
    char c = s[s.size()-1-i];

    if (c == '-')
    {
      sum *= -1;
      continue;
    }

    int partial = s[s.size()-1-i] - '0';
    if (not (partial >= 0 && partial < 10)) continue;
    
    partial *= pow(10, i);
    sum += partial;
  }
  return sum;
}

int main()
{
  string a = "123";
  string b = "2324";
  string c = "00234";
  string d = "-00234";
  string e = "-434";

  printf("%s %s %s %s %s\n", a.c_str(), b.c_str(), c.c_str(), d.c_str(), e.c_str());
  printf("%d %d %d %d %d\n", a2i(a), a2i(b), a2i(c), a2i(d), a2i(e));
}
