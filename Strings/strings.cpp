#include <stdio.h>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <deque>
#include <cmath>

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

/*
starting index, ending index
starting index is start of string
for each character in the string
  if current character is a space, set ending index to that index
    add substring to deque of strings
    set starting index to the current character
    continue
  else increment ending pointer

read deque backwards and add each word to a new string
*/

void reverseStringWords(string input)
{
  if (input.size() == 0) return;

  int startingindex = 0, endingindex = 0;
  deque<string> words;
  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] == ' ')
    {
      words.push_front(input.substr(startingindex, endingindex-startingindex));
      startingindex = i+1;
    }
    if (i == input.size() - 1)
    {
      words.push_front(input.substr(startingindex, endingindex-startingindex+1));
    }
    endingindex++;
  }

  for (int i = 0; i < words.size(); i++)
  {
    printf("%s", words[i].c_str());
    if (i != words.size() - 1)
    {
      printf(" ");
    }
  }
}


/*
size = s
s-1 ones place
s-2 is tens
s-3 is hundreds

walk through string backwards
  if (chr == 0) //do nothing
  if (chr == 1) multiply by 1 * 10 to the s-value
*/
int stringToInt(string input)
{
  int intvalue = 0;
  for (int i = 0; i < input.size(); i++)
  {
    intvalue += ((input[input.size()-i-1] - '0') * pow(10,i));
  }
  return intvalue;
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

  reverseStringWords("Do or do not, there is no try.");

  printf("\nstringtoint: %d\n", stringToInt("45601"));
}
