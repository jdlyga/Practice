#include <iostream>
#include <deque>

using namespace std;


class PathNode
{
  public:

    PathNode(int row, int col) : row(row), col(col) {};

    int row;
    int col;
    PathNode * right = NULL;
    PathNode * down = NULL;
    PathNode * parent = NULL;
};
////////////////////////////////////////////////////////////////////////////////


void displayPath(PathNode * goal)
{
  deque<PathNode*> path;
  PathNode * node = goal;

  while (node->parent != NULL)
  {
    path.push_front(node);
    node = node->parent;
  }

  for (int i = 0; i < path.size(); i++)
  {
    node = path[i];
    printf("%d, %d\n", node->row, node->col);
  }

}
////////////////////////////////////////////////////////////////////////////////


void buildTree(PathNode * node, deque<deque<bool>> & grid, int numRows, int numCols, PathNode *& goalNode)
{
  if (goalNode != NULL) return;

  //check goal found
  if (node->row == numRows-1 && node->col == numCols-1)
  {
    cout << "GOAL FOUND!\n";
    goalNode = node;
    return;
  }

  //check right path
  if (node->col + 1 < numCols)
  {
    if (grid[node->col+1][node->row])
    {
      node->right = new PathNode(node->row, node->col+1);
      node->right->parent = node;
      buildTree(node->right, grid, numRows, numCols, goalNode);
    }
  }

  if (goalNode != NULL) return;

  //check bottom path
  if (node->row + 1 < numRows)
  {
    if (grid[node->col][node->row+1])
    {
      node->down = new PathNode(node->row+1, node->col);
      node->down->parent = node;
      buildTree(node->down, grid, numRows, numCols, goalNode);
    }
  }
}
////////////////////////////////////////////////////////////////////////////////


void buildTree(PathNode * node, deque<deque<bool>> & grid, int numRows, int numCols)
{
  PathNode * goalNode = NULL;
  buildTree(node, grid, numRows, numCols, goalNode);

  if (goalNode != NULL)
  {
    printf("Found Path!\n");
    displayPath(goalNode);
  }
  else
  {
    printf("Could not find a path\n");
  }
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  deque<deque<bool>> grid = 
  {{true, true, true, true, true},
   {true, false, true, false, true},
   {false, false, true, true, true},
   {false, true, false, true, false},
   {false, true, false, true, false},
   {false, true, true, true, true},
   {false, true, true, true, true},
   {false, true, true, true, true}};

   PathNode * root = new PathNode(0,0);
   buildTree(root, grid, 5, 8);
}
