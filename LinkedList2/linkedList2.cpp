#include <stdio.h>
#include <cstdint>


struct linkedList
{
  int data;
  struct linkedList * next = NULL;
};

linkedList * head = NULL;
linkedList * tail = NULL;

bool findInList(linkedList * elem)
{
  linkedList * walker = head;
  while (walker != NULL)
  {
    if (walker == elem)
    {
      return true;
    }
    walker = walker->next;
  }
  return false;
}


bool insertAfter(linkedList * elem, int data)
{
  if (elem != NULL)
  {
    if (!findInList(elem))
      return false;
  }

  linkedList * newElem = new linkedList;
  newElem->data = data;

  if (head != NULL && elem == NULL)
  {
    newElem->next = head;
    head = newElem;
  }
  else if (head == NULL || elem == NULL)
    head = newElem;

  if (tail == NULL || elem == tail)
    tail = newElem;

  if (elem != NULL)
  {
    newElem->next = elem->next;
    elem->next = newElem;
  }
}
////////////////////////////////////////////////////////


bool deleteMe(linkedList * elem)
{

  if (!findInList(elem))
    return false;

  if (elem == head && elem == tail)
  {

    delete elem;
    head = NULL;
    tail = NULL;
    return true;
  }


  if (elem == head)
  {

    head = head->next;
    delete elem;
    return true;
  }

  linkedList * beforeElem = head;
  while (beforeElem->next != elem)
  {
    beforeElem = beforeElem->next;
  }
  beforeElem->next = elem->next;

  if (elem == tail)
  {
    beforeElem = tail;
  }

  delete elem;
  return true;
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  insertAfter(NULL, 1);
  insertAfter(NULL, 2);
  insertAfter(NULL, 3);
  insertAfter(NULL, 4);
  linkedList * oldtail = tail;
  insertAfter(tail, 5);
  insertAfter(tail, 6);
  insertAfter(oldtail, 7);

  linkedList * ptr = head;
  while (ptr != NULL)
  {
    printf("Data Elem: %d\n", ptr->data);
    ptr = ptr->next;
  }

  printf("\n\n");

  deleteMe(oldtail);
  deleteMe(head);
  deleteMe(tail);

  ptr = head;
  while (ptr != NULL)
  {
    printf("Data Elem: %d\n", ptr->data);
    ptr = ptr->next;
  }
}
