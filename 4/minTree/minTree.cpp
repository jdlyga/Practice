#include <cstdio>
#include <string>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Node
{
  public:

    Node(int d) : data(d) {};
    ~Node() {};

    int data;
    Node * left = NULL;
    Node * right = NULL;
};


void makeBST(vector<int> & v, int left, int right, Node *& root)
{
  if (left > right) return;
  int center = (left + right) / 2;
  root = new Node(v[center]);
  makeBST(v, left, center-1, root->left);
  makeBST(v, center+1, right, root->right);
}

void printTreeDFS(Node * root, int depth = 0)
{
  if (root != NULL)
  {
    cout << depth << ") " << root->data << endl;
    printTreeDFS(root->left, depth+1);
    printTreeDFS(root->right, depth+1);
  }
}

void printTreeBFS(Node * root)
{
  queue<Node*> nodequeue;
  nodequeue.push(root);

  while (!nodequeue.empty())
  {
    Node * node = nodequeue.front();
    nodequeue.pop();

    cout << node->data << endl;

    if (node->left != NULL)
      nodequeue.push(node->left);
    if (node->right != NULL)
      nodequeue.push(node->right);
  }
}

void makeLL(map<int, deque<int> > & m, Node * root, int depth = 0)
{
  if (root == NULL) return;
  m[depth].push_back(root->data);
  makeLL(m, root->left, depth+1);
  makeLL(m, root->right, depth+1);
}

void printMap(map<int, deque<int> > & m)
{
  for (auto elem : m)
  {
    for (int i = 0; i < elem.second.size(); i++)
    {
      cout << elem.first << ") " << elem.second[i] << endl;
    }
    cout << endl;
  }
}

int main()
{
  Node * root = NULL;
  vector<int> v = {1, 3, 5, 7, 8, 9, 10, 11, 23, 45, 54, 73, 81, 90};
  makeBST(v, 0, v.size()-1, root);

  printTreeDFS(root);

  cout << "======================================================" << endl;

  map<int, deque<int> > m;
  makeLL(m, root);
  printMap(m);

  return 0;
}
