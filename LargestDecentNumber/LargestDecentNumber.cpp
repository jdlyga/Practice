#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int getCount(const string & str, char c)
{
  int sum = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == c)
      sum++;
  }
  return sum;
}
//////////////////////////////////////////////////////////////////


bool findNextNumber(string & number, int index)
{
  if (index == -1)
  {
    //printf("DONE\n");
    return false;
  }
    
  if (number[index] == '3')
  {
    number[index] = '5';
    return true;
  }
  else //if (number[index] == '5')
  {
    number[index] = '3';
    return findNextNumber(number, index-1);
  }
  return false;
}
//////////////////////////////////////////////////////////////////


void getAllNumbers(const int numDigits, deque<string> & numbers)
{
  string num;
  for (size_t i = 0; i < numDigits; i++)
  {
    num += '3';
  }
    
  do
  {
    //printf("!num: %s\n", num.c_str());
    numbers.push_back(num);
  } while (findNextNumber(num, num.size()-1));
}
//////////////////////////////////////////////////////////////////


string findMaxDecentNumber(int numDigits)
{
  deque<string> numbers;
  deque<string> decentNumbers;
  getAllNumbers(numDigits, numbers);

  string largestDecentNumber = "";
  for (int i = 0; i < numbers.size(); i++)
  {
    if (((getCount(numbers[i], '3') % 5) == 0) &&
        ((getCount(numbers[i], '5') % 3) == 0))
      largestDecentNumber = numbers[i];
  }
  
  if (largestDecentNumber == "")
    return "-1";
  else
  {
    return largestDecentNumber;
  }
}
//////////////////////////////////////////////////////////////////


int main()
{
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++)
  {
    int n;
    cin >> n;
    cout << findMaxDecentNumber(n) << endl;
  }
  
  return 0;
}
