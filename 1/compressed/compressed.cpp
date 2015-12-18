#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

string findCompressed(string a)
{
  deque<std::tuple<char, int> > comp;

  int count = 0;
  char current = '\0';

  for (char c : a)
  {
    if (count == 0 && current == '\0')
    {
      count = 1;
      current = c;
      continue;
    }
    if (c == current)
    {
      count++;
      continue;
    }
    else
    {
      comp.push_back(std::make_tuple(current, count));
      count = 1;
      current = c;
      continue;
    }
  }

  if (count != 0 && current != '\0')
    comp.push_back(std::make_tuple(current, count));

  string b;

  for (int i = 0; i < comp.size(); i++)
  {
    b += get<0>(comp[i]);
    b += to_string(get<1>(comp[i]));
  }
  
  if (b.length() < a.length())
    return b;
  else
    return a;
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  string a = "aaaabbbbbcccefg";
  string b = "aavbsdfsgsrhr";
  string c = "egweweywe";
  string d = "eeeetttttttttttttttttttttttttttttggggg";
  string e = "tttttttttttttteeeeeeeeehghh";

  a = findCompressed(a);
  b = findCompressed(b);
  c = findCompressed(c);
  d = findCompressed(d);
  e = findCompressed(e);

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  
  return 0;
}
