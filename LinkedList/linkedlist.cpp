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


bool popFront(linkedList<string> *& head, string & data)
{
  if (head == NULL)
    return false;
  else if (head->next == NULL)
  {
    data = head->data;
    delete head;
    head = NULL;
  }
  else
  {
    linkedList<string> * newHead = head->next;
    data = head->data;
    delete head;
    head = newHead;
  }
  return true;
}
////////////////////////////////////////////////////////////////////////////////


bool deleteAll(linkedList<string> *& head)
{
  linkedList<string> * ptr = head;
  linkedList<string> * deleteMe = head;

  while(ptr != NULL)
  {
    ptr = ptr->next;
    delete deleteMe;
    deleteMe = ptr;
  }
  head = NULL;
  return true;
}
////////////////////////////////////////////////////////////////////////////////


linkedList<string> * find(linkedList<string> & head, string findstr)
{
  linkedList<string> * ptr = &head;
  while (ptr != NULL)
  {
    if (ptr->data == findstr)
      return ptr;
    ptr = ptr->next;
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

  linkedList<string> * ptr = head;
  while (ptr != NULL)
  {
    printf("HERE IT IS: %s\n", ptr->data.c_str());
    ptr = ptr->next;
  }

  string data;
  popFront(head, data);
  printf("popped %s\n", data.c_str());
  popFront(head, data);
  printf("popped %s\n", data.c_str());
  popFront(head, data);
  printf("popped %s\n", data.c_str());

  ptr = head;
  while (ptr != NULL)
  {
    printf("HERE IT IS AGAIN: %s\n", ptr->data.c_str());
    ptr = ptr->next;
  }
  printf("TADA!\n");

  deleteAll(head);

  ptr = head;
  while (ptr != NULL)
  {
    printf("HERE IT IS AGAIN AGAIN: %s\n", ptr->data.c_str());
    ptr = ptr->next;
  }
  printf("nothing in it!\n");
}
////////////////////////////////////////////////////////////////////////////////
