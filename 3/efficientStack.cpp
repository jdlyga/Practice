#include <cstdlib>
#include <cstdio>
#include <stack>

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
    void removeFront();
    void print();
    void removeDuplicates();
    linkedNode * kthToLast(int k);

    linkedNode * head = NULL;
};


class stack
{
  public:
    stack() {};
    ~stack() {};
    void push(int n);
    int pop();
    void print();
    int getSize() {return size;};
    int getMin();

  private:

    linkedList minList;
    linkedList list;
    int size = 0;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
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


void linkedList::removeFront()
{
  if (head == NULL) return;

  linkedNode * newhead = head->next;
  delete head;
  head = newhead;
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
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void stack::push(int n)
{
  size++;
  list.insertFront(n);

  if (minList.head == NULL)
  {
    minList.insertFront(n);
  }
  else if (n <= minList.head->data)
  {
    minList.insertFront(n);
  }
}
////////////////////////////////////////////////////////////////////////////////


int stack::pop()
{
  if (list.head == NULL) return -1;

  size--;
  int n = list.head->data;
  list.removeFront();

  if (n == minList.head->data)
  {
    minList.removeFront();
  }

  return n;
}
////////////////////////////////////////////////////////////////////////////////


void stack::print()
{
  list.print();
}
////////////////////////////////////////////////////////////////////////////////


int stack::getMin()
{
  if (minList.head == NULL) 
    return -1;
  else
    return minList.head->data;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
  stack stk;
  stk.push(5);
  stk.push(3);
  stk.push(2);
  stk.push(7);
  stk.push(1);
  stk.push(9);
  stk.push(0);
  stk.push(0);
  stk.print();
  printf("\n");

  while (stk.getSize() > 0)
  {
    printf("min: %d\n", stk.getMin());
    stk.pop();
  }

  return 0;

}


