#include <stdio.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////


typedef struct linkedList
{
  string str;
  linkedList * next;
} linkedList;


template <class T>
class listElement
{
  public:
    listElement(const T & value)
      : data(value)
    {}
    ~listElement()
    {}

    listElement * next = NULL;
    T data;
};

bool insertInFront(listElement<string> ** head, string data)
{
  listElement<string> * newElem = new listElement<string>(data);
  if (not newElem) return false;
  newElem->data = data;
  newElem->next = *head;
  *head = newElem;
  return true;
}

int main()
{
  printf("Hi!\n");

  listElement<string> * head = NULL;
  insertInFront(&head, "panda");
  insertInFront(&head, "salad");
  insertInFront(&head, "sandwich");
  insertInFront(&head, "apple");
  insertInFront(&head, "1");
  insertInFront(&head, "2");
  insertInFront(&head, "3");
  insertInFront(&head, "4");
  insertInFront(&head, "5");
  insertInFront(&head, "6");

  while (head->next != NULL)
  {
    printf("head data: %s\n", head->data.c_str());
    head = head->next;
  }

}
////////////////////////////////////////////////////////////////////////////////
