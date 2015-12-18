#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;


bool testUnique(string str)
{
  deque<char> strd;

  for (int i = 0; i < str.size(); i++)
  {
    strd.push_back(tolower(str[i]));
  }
  std::sort(strd.begin(), strd.end(), std::greater<char>());

  for (int i = 0; i < strd.size()-1; i++)
  {
    if (strd[i] == strd[i+1])
      return false;
  }
  return true;
}

int main()
{
  string str1 = "hola";
  string str2 = "test";
  string str3 = "test string";
  string str4 = "good";
  string str5 = "pandy";

  cout << testUnique(str1) << endl;
  cout << testUnique(str2) << endl;
  cout << testUnique(str3) << endl;
  cout << testUnique(str4) << endl;
  cout << testUnique(str5) << endl;
}
