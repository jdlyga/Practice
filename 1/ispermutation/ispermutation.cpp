#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

bool isPermutation(string a, string b)
{
  std::sort(a.begin(), a.end(), std::greater<char>());
  std::sort(b.begin(), b.end(), std::greater<char>());

  return (a == b);
}

int main()
{
  string a = "panda";
  string b = "adpan";
  string c = "dog";
  string d = "god";
  string e = "gof";
  string f = "gor";

  cout << isPermutation(a, b) << endl;
  cout << isPermutation(c, d) << endl;
  cout << isPermutation(e, f) << endl;
  
  return 0;
}
