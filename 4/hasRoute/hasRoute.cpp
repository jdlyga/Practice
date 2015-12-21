#include <cstdio>
#include <string>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

class Node
{
  public:

    Node(int d) : data(d) {};
    ~Node() {};

    int data;
    bool visited = false;
    std::deque<Node*> children;
};

bool hasRoute(Node * startingNode, Node * endingNode)
{
  std::queue<Node*> nodequeue;
  startingNode->visited = true;
  nodequeue.push(startingNode);

  while (!nodequeue.empty())
  {
    Node * testNode = nodequeue.front();
    nodequeue.pop();

    if (!testNode->visited)
    {
      testNode->visited = true;
      // cout << "Node: " << testNode->data << endl;
    }

    if (testNode == endingNode)
      return true;

    for (int i = 0; i < testNode->children.size(); i++)
    {
      if (! testNode->children[i]->visited)
      {
        testNode->visited = true;
        nodequeue.push(testNode->children[i]);
      }
    }
  }
  return false;
}

int main()
{
  Node n0(0);
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  Node n5(5);
  Node n6(6);

  cout << "Node Data: " << n1.data << endl;

  n0.children.push_back(&n1);
  n0.children.push_back(&n4);
  n0.children.push_back(&n5);

  n1.children.push_back(&n4);
  n1.children.push_back(&n3);
  
  n2.children.push_back(&n1);

  n3.children.push_back(&n2);
  n3.children.push_back(&n4);

  // cout << (hasRoute(&n0, &n1) ? "Yes" : "No") << endl;
  // cout << (hasRoute(&n0, &n2) ? "Yes" : "No") << endl;
  // cout << (hasRoute(&n0, &n3) ? "Yes" : "No") << endl;
  // cout << (hasRoute(&n0, &n4) ? "Yes" : "No") << endl;
  cout << (hasRoute(&n0, &n5) ? "Yes" : "No") << endl;
  // cout << (hasRoute(&n0, &n6) ? "Yes" : "No") << endl;

  return 0;
}
