#include <vector>
#include <iostream>
#include <climits>
using namespace std;

void findLargestSubsequence(vector<int> & v)
{
  int N = v.size();
  int sum = v[0];
  int largestSum = INT_MIN;

  if (N < 2) 
  {
    cout << "Not a correct sequence" << endl;
    return;
  }
  
  for (int end = 1; end < N; end++)
  {
    sum += v[end];

    if (sum > largestSum)
    {
      largestSum = sum;
    }
    else if (sum < 0)
    {
      sum = 0;
      if (end + 1 < N) 
        sum = v[end + 1];
    }
  }

  cout << "Sum: " << largestSum << endl;
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  vector<int> v0 = {2, -4};
  vector<int> v1 = {2};
  vector<int> v2 = {2, -8, 3, -2, 4, -10};
  vector<int> v3 = {2, -2, 2, -8, 2, -17, 8, -2, 100, -40};
  vector<int> v4 = {1, -8, 9, -2, 5, -11, 6, -2, 3, -2, 4, -10};
  vector<int> v5 = {1, -8, 5, -2, 5, -12, 2, -2, 1, -2, 5, -10, 3, -8, 2, -2, 4, -10};
  vector<int> v6 = {100, -20, 20, -10, 424, -53, 644, -36, 364634, -3, 236236, 
                   -230, 235, -14, 1, -1, 1, -1, 1, -1, 24312, -14, -2141414, 
                   1412, -1424, 14244, -12414, 4, -5, 1, -5, 2, -8, 3, -2, 4, -10};

  findLargestSubsequence(v0);
  findLargestSubsequence(v1);
  findLargestSubsequence(v2);
  findLargestSubsequence(v3);
  findLargestSubsequence(v4);
  findLargestSubsequence(v5);
  findLargestSubsequence(v6);
}
