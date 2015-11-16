#include <stdio.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////

template <class TYPE>
struct linkedList
{
  TYPE data;
  linkedList * next = NULL;
};
////////////////////////////////////////////////////////////////////////////////


void insertInFront(linkedList<string> *& head, string data)
{
  linkedList<string> * newElem = new linkedList<string>;
  newElem->data = data;
  newElem->next = head;
  head = newElem;
}
////////////////////////////////////////////////////////////////////////////////


void insertInBack(linkedList<string> *& head, string data)
{
  linkedList<string> * newElem = new linkedList<string>;
  newElem->data = data;
  newElem->next = NULL;

  linkedList<string> * ptr = head;
  if (ptr == NULL)
  {
    head = newElem;
  }
  else
  {
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = newElem;
  }
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  printf("Hi!\n");

  linkedList<string> * head = NULL;
  insertInBack(head, "panda");
  insertInBack(head, "salad");
  insertInBack(head, "sandwich");
  insertInBack(head, "apple");
  insertInBack(head, "1");
  insertInBack(head, "2");
  insertInBack(head, "3");
  insertInBack(head, "4");
  insertInBack(head, "5");
  insertInBack(head, "6");

  while (head != NULL)
  {
    printf("HERE IT IS: %s\n", head->data.c_str());
    head = head->next;
  }
}
////////////////////////////////////////////////////////////////////////////////
