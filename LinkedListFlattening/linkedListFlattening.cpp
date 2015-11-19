#include <stdio.h>
#include <cstdint>

struct Node
{
  struct Node * next;
  struct Node * prev;
  struct Node * child;
  int value;
};

Node * nodePtr;

void addToList(Node * ptr, int data)
{
  printf("foobar\n");
}


void flattenList(Node *& node)
{
  if (node->child != NULL)
  {
    flattenList(node->child);
  }

  if (node->next != NULL)
  {
    flattenList(node->next);
  }

  addToList(nodePtr, node->value);
}


int main()
{

}
