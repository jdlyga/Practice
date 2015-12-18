#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

void reverse(char * str)
{
  unsigned int len = strlen(str);
  int lidx = 0;
  int ridx = len-1;
  while (lidx < ridx)
  {
    std::swap(str[lidx], str[ridx]);
    lidx++;
    ridx--;
  }
}


int main()
{
  string str1 = "apple";
  string str2 = "dog";
  string str3 = "peanut";
  string str4 = "sandwich";

  char * cstr1 = (char *)str1.c_str();
  char * cstr2 = (char *)str2.c_str();
  char * cstr3 = (char *)str3.c_str();
  char * cstr4 = (char *)str4.c_str();

  reverse(cstr1);
  reverse(cstr2);
  reverse(cstr3);
  reverse(cstr4);

  cout << cstr1 << endl;
  cout << cstr2 << endl;
  cout << cstr3 << endl;
  cout << cstr4 << endl;
}
