#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
  printf("Hello World!\n");

  int64_t sum = 1;
  deque<int64_t> fibbydeque {1, 1};

  auto printSeries = [&sum](int index) { cout << index << ":  " << sum << endl; };

  printSeries(0);
  printSeries(1);

  for (int i = 2; i < 50; i++)
  {
    fibbydeque.push_back(sum);
    fibbydeque.pop_front();
    sum = fibbydeque[0] + fibbydeque[1];
    printSeries(i);
  }
}
