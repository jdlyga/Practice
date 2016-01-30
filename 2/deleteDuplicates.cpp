#include <cstdlib>
#include <cstdio>
#include <set>

using std::set;

class linkedNode
{
  public:
    linkedNode() {};
    ~linkedNode() {};

    int data;
    linkedNode * next = NULL;
};


class linkedList
{
  public:
    linkedList() {};
    ~linkedList() {};
    void insertFront(int n);
    void insertBack(int n);
    void print();
    void removeDuplicates();
    linkedNode * kthToLast(int k);

    linkedNode * head = NULL;
};
////////////////////////////////////////////////////////////////////////////////


void linkedList::insertFront(int n)
{
  linkedNode * node = new linkedNode();
  node->data = n;

  if (head == NULL)
  {
    head = node;
  }
  else
  {
    node->next = head;
    head = node;
  }
}
////////////////////////////////////////////////////////////////////////////////


void linkedList::insertBack(int n)
{
  linkedNode * lastNode = head;

  if (head == NULL)
  {
    head = new linkedNode();
    head->data = n;
  }
  else
  {
    while (lastNode->next != NULL)
    {
      lastNode = lastNode->next;
    }

    linkedNode * node = new linkedNode();
    node->data = n;
    lastNode->next = node;
  }
}
////////////////////////////////////////////////////////////////////////////////


void linkedList::print()
{
  linkedNode * node = head;
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
}
////////////////////////////////////////////////////////////////////////////////


void linkedList::removeDuplicates()
{
  set<int> intSet; 
  linkedNode * prev = NULL;
  linkedNode * node = head;

  while (node != NULL)
  {
    if (intSet.find(node->data) != intSet.end())
    {
      prev->next = node->next;
      delete node;
      node = prev;
    }
    else
    {
      intSet.insert(node->data);
    }

    prev = node;
    node = node->next;
  }
}
////////////////////////////////////////////////////////////////////////////////


linkedNode * linkedList::kthToLast(int k)
{
  linkedNode * node = head;
  linkedNode * kthNode = head;

  while (node != NULL)
  {
    if (k > 0) 
    {
      k--;
    }
    else
    {
      kthNode = kthNode->next;
    }

    node = node->next;
  }
  return kthNode;
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  linkedList list;
  list.insertBack(5);
  list.insertBack(5);
  list.insertBack(4);
  list.insertBack(4);
  list.insertBack(3);
  list.insertBack(2);
  list.insertBack(2);
  list.insertBack(1);
  list.print();
  printf("\n\n");
  list.removeDuplicates();
  list.print();

  linkedNode * kth = list.kthToLast(3);
  printf("\n\n");
  printf("3rd to last: %d\n", kth->data);
}
