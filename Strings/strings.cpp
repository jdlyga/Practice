#include <stdio.h>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;


char findFirstUniqueChar(const string & str)
{
  map<char, int> charCounter;

  for (auto chr : str)
  {
    charCounter[chr]++;
    printf("char count: %c: %d\n", chr, charCounter[chr]);
  }

  for (auto chr : str)
  {
    if (charCounter[chr] == 1)
    {
      return chr;
    }
  }

  return '\0';
}


// for each element in the string
//   if it's a member of the to remove string, then set it to \0
// swap \0 elements to the end
  



string removeFromString(const string & input, string toRemove)
{
  deque<char> newchars;
  for (int i = 0; i < input.size(); i++)
  {
    char chr = input[i];
    for (auto removalChr : toRemove)
    {
      if (chr == removalChr)
      {
        chr = '\0';
        break;
      }
    }
    if (chr != '\0')
    {
      newchars.push_back(chr);
    }
  }

  string newstr(newchars.size(), '\0');
  for (int i = 0; i < newstr.size(); i++)
  {
    newstr[i] = newchars[i];
  }

  return newstr;
}

//uses a c++ hash table (unordered map)
string removeFromStringBetter(string & input, string toRemove)
{
  unordered_map<char, bool> removalChars;
  for (char chr : toRemove)
  {
    removalChars[chr] = true;
  }

  int startingIndex = 0;
  int endingIndex = 0;

  for (startingIndex; startingIndex < input.size(); startingIndex++)
  {
    char chr = input[startingIndex];
    input[endingIndex] = input[startingIndex];
    if (not removalChars[chr])
    {
      endingIndex++;
    }
  }
  input.resize(endingIndex);
  return input;
}



int main()
{
  string total = "total";
  string teeter = "teeter";
  string sample = "ssaatmmn";

  char c1 = findFirstUniqueChar(total);
  char c2 = findFirstUniqueChar(teeter);
  char c3 = findFirstUniqueChar(sample);

  printf("%c %c %c\n", c1, c2, c3);

  string testingStr = "Battle of the Vowels: Hawaii vs. Grozny";
  string newStr = removeFromStringBetter(testingStr, "aeiou");
  printf("newStr: %s\n", newStr.c_str());
}
