#include <stdio.h>
#include <cstdint>
#include <algorithm>
#include <stack>

class binaryTree
{
  public:

    binaryTree(int data);
    ~binaryTree();

    bool insertLeft(int data);
    bool insertRight(int data);

    int findHeight(int heightCounter = 1);
    void preorderTraversal();
    void preorderTraversalNoRecursion();
    int lowestCommonAncestor(int num1, int num2);

    int data;
    binaryTree * left = NULL;
    binaryTree * right = NULL;

};


binaryTree::binaryTree(int data)
  : data(data)
{}

bool binaryTree::insertLeft(int data)
{
  if (left != NULL) 
    return false;
  else
  {
    left = new binaryTree(data);
  }
}

bool binaryTree::insertRight(int data)
{
  if (right != NULL)
    return false;
  else
  {
    right = new binaryTree(data);
  }
}

int binaryTree::findHeight(int heightCounter)
{
  int leftCounter = -1;
  if (left != NULL) leftCounter = left->findHeight(heightCounter + 1);

  int rightCounter = -1;
  if (right != NULL) rightCounter = right->findHeight(heightCounter + 1);

  if (left == NULL && right == NULL)
    return heightCounter;
  else
    return std::max(leftCounter, rightCounter);
}

void binaryTree::preorderTraversal()
{
  printf("Node: %d\n", data);

  if (left != NULL) left->preorderTraversal();
  if (right != NULL) right->preorderTraversal();
}


void binaryTree::preorderTraversalNoRecursion()
{
  std::stack<binaryTree*> nodeStack;

  // printf("Node: %d\n", data);

  nodeStack.push(this);
  binaryTree * ptr;
  while (nodeStack.size() > 0)
  {
    ptr = nodeStack.top();
    nodeStack.pop();
    printf("Node: %d\n", ptr->data);
    
    if (ptr->right != NULL)
    {
      nodeStack.push(ptr->right);
    }
    if (ptr->left != NULL)
    {
      nodeStack.push(ptr->left);
    }
  }
}

int binaryTree::lowestCommonAncestor(int num1, int num2)
{
  if ((num1 < data) && (num2 < data))
  {
    printf("left\n");
    return left->lowestCommonAncestor(num1, num2);
  }
  else if ((num1 > data) && (num2 > data))
  {
    printf("right\n");
    return right->lowestCommonAncestor(num1, num2);
  }
  else
  {
    printf("this");
    return data;
  }
}






int main()
{
  binaryTree * root = new binaryTree(1);
  binaryTree * ptr;
  root->insertLeft(3);
  root->insertRight(4);
  ptr = root->left;
  ptr->insertLeft(7);
  ptr->insertRight(9);
  ptr = ptr->left;
  ptr->insertLeft(8);
  ptr->insertRight(6);
  // ptr = ptr->right;
  // ptr->insertLeft(2);
  // ptr->insertRight(4);
  // ptr->right->insertLeft(2);
  // ptr->left->insertRight(1);

  printf("Height: %d\n", root->findHeight());
  root->preorderTraversal();
  root->preorderTraversalNoRecursion();

  binaryTree * binarySearchTree = new binaryTree(20);
  binarySearchTree->insertLeft(8);
  binarySearchTree->insertRight(22);
  ptr = binarySearchTree->left;
  ptr->insertLeft(4);
  ptr->insertRight(12);
  ptr = ptr->right;
  ptr->insertLeft(10);
  ptr->insertRight(14);

  printf("AA\n");
  printf("lowest: %d\n", binarySearchTree->lowestCommonAncestor(4, 14));
}






