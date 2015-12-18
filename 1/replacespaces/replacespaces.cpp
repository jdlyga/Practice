#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

void replaceSpaces(string & a)
{
  string b;
  for (char c : a)
  {
    if (c == ' ')
      b += "%%20";
    else
      b += c;
  }
  a = b;
}

int main()
{
  string a = "pa   nda";
  string b = "ad  pan";
  string c = "do g";
  string d = "gsod";
  string e = "goffry";
  string f = "go  r";

  replaceSpaces(a);
  replaceSpaces(b);
  replaceSpaces(c);
  replaceSpaces(d);
  replaceSpaces(e);
  replaceSpaces(f);

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  cout << f << endl;
  
  return 0;
}
