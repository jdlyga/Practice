#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> v = {2, -8, 3, -2, 4, -10};
  int N = v.size();

  int start = 0;
  int sum = v[start];
  int largestSum = -1;
  for (int end = 1; end < N, start < N; end++)
  {
    sum += v[end];
    if (sum > largestSum)
      largestSum = sum;

    if (sum < 0)
    {
      sum = 0;
      start = end + 1;
      end = start;
      if (start < N) 
        sum = v[start];
    }
  }

  cout << "Sum: " << largestSum;
}
