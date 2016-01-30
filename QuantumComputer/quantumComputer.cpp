#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <deque>
#include <set>
using namespace std;

int rows, cols;

class plusType
{
  public:
  
    plusType() {};
    plusType(int v, int s) : vertex(v), size(s) {};
    void getIndices(set<int> & Indices) const
    {
      int left, right, top, bottom;
      left = vertex; right = vertex; top = vertex; bottom = vertex;
      for (int i = 0; i < size; i++)
      {
        Indices.insert(left);
        Indices.insert(right);
        Indices.insert(top);
        Indices.insert(bottom);
        left -= 1;
        right += 1;
        top -= cols;
        bottom += cols;
      }
    }
    int getArea()
    {
      return (size-1)*4 + 1;
    }
  
    int vertex;
    int size;
};
///////////////////////////////////////////////////////////////////



bool doesOverlap(const plusType & a, const plusType & b)
{
  set<int> aidxs, bidxs;
  a.getIndices(aidxs);
  b.getIndices(bidxs);
  
  vector<int> overlappingIndices;
  std::set_intersection(aidxs.begin(), aidxs.end(), bidxs.begin(), bidxs.end(), std::back_inserter(overlappingIndices));
  
  return (overlappingIndices.size() > 0);
}
///////////////////////////////////////////////////////////////////


void findBestNonOverlapping(deque<plusType> & candidatePluses, plusType & best1, plusType & best2, int & maxProduct)
{
  plusType test1, test2;
  //now find 2 largest that don't overlap
  for (int i = 0; i < candidatePluses.size(); i++)
  {
    test1 = candidatePluses[i];
    for (int j = 0; j < candidatePluses.size(); j++)
    {
      test2 = candidatePluses[j];
      
      //printf("testing %d of size %d with %d of size %d\n", best1.vertex, best1.size, best2.vertex, best2.size);
      if (!doesOverlap(test1, test2))
      {
        //cout << maxProduct;
        int testVal = test1.getArea() * test2.getArea();
        if (testVal > maxProduct)
        {
          best1 = test1;
          best2 = test2;
          maxProduct = testVal;
        }
      }
    }
  }
}
///////////////////////////////////////////////////////////////////


void findCandidatePluses(deque<bool> & grid, deque<plusType> & candidatePluses)
{
  //find all candidate pluses
  for (int i = 0; i < grid.size(); i++)
  {
    if (grid[i])
    {
      candidatePluses.push_back(plusType(i, 1));
      int currentSize = 1;
      int left = i-1;
      int right = i+1;
      int top = i - cols;
      int bottom = i + cols;
      
      while (true)
      {
        if (((right % cols) - (left % cols) != 2) || ((top < 0) || (bottom > (rows*cols)-1)))
          break;

        if (grid[left] && grid[right] && grid[top] && grid[bottom])
        {
          left--;
          right++;
          top -= cols;
          bottom += cols;
          currentSize++;
          //printf("current size: %d\n", currentSize);
          candidatePluses.push_back(plusType(i, currentSize));
          continue;
        }
        else
          break;
      }
    }
  }
}
///////////////////////////////////////////////////////////////////


int main() 
{
  cin >> rows >> cols;
  deque<bool> grid;
  for (int i = 0; i < rows; i++)
  {
    string rowstr;
    cin >> rowstr;
    for (char c : rowstr)
    {
      if (c == 'G')
        grid.push_back(true);
      else
        grid.push_back(false);
    }
  }
  
  deque<plusType> candidatePluses;
  findCandidatePluses(grid, candidatePluses);
  
  std::sort(candidatePluses.begin(), candidatePluses.end(), [](plusType a, plusType b)
  {
    return a.size > b.size;
  });
  
  plusType best1, best2;
  int maxProduct = 0;
  findBestNonOverlapping(candidatePluses, best1, best2, maxProduct);
  //printf("best1: %d of size %d\nbest2: %d of size %d\n", best1.vertex, best1.size, best2.vertex, best2.size);
   
  /*
  set<int> aidxs, bidxs;
  best1.getIndices(aidxs);
  best2.getIndices(bidxs);
  

  for (auto a : aidxs)
  {
    printf("a: %d\n", a);
  }
  for (auto b : aidxs)
  {
    printf("b: %d\n", b);
  }
  vector<int> overlappingIndices;
  std::set_intersection(aidxs.begin(), aidxs.end(), bidxs.begin(), bidxs.end(), std::back_inserter(overlappingIndices));  
  
  printf("overlapping size: %d\n", overlappingIndices.size());
  for (auto a : overlappingIndices)
  {
    printf("overlap: %d\n", a);
  }
  */
  
  cout << maxProduct;
  return 0;
}
