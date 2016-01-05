#include <iostream>


void reverseString(char * str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  int size = i;
  int start = 0, end = size-1;

  while (start <= end)
  {
    std::swap(str[start], str[end]);
    start++;
    end--;
  }
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  char str[] = "Banana";
  printf("%s\n", str);
  reverseString(str);
  printf("%s\n", str);
}
