#include <cstdio>

using namespace std;

const int SIZE = 20;
const int HASHSIZE = 2;

class Node
{
  public:

    Node();
    Node(int key, int value);

    int key, value;
};

class HashTable
{
  public:

    HashTable();

    bool insert(int key, int value);
    Node* get(int key);

  private:

    inline int hashFunction(int value);
    int findOpenBucket(int startingkey);
    Node * data[SIZE];
};
////////////////////////////////////////////////////////////////////////////////


Node::Node()
{}
////////////////////////////////////////////////////////////////////////////////


Node::Node(int key, int value)
  : key(key), value(value)
{}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


HashTable::HashTable()
{
  for (int i = 0; i < SIZE; i++)
  {
    data[i] = NULL;
  }
}
////////////////////////////////////////////////////////////////////////////////


bool HashTable::insert(int key, int value)
{
  int hashValue = hashFunction(key);
  int bucket = hashValue % SIZE;

  Node * node = data[bucket];

  if (node != NULL)
  {
    bucket = findOpenBucket(bucket);
    if (bucket == -1)
    {
      printf("Error:  HashTable is full!\n");
      return false;
    }
  }

  node = new Node(key, value);
  data[bucket] = node;
}
////////////////////////////////////////////////////////////////////////////////


Node* HashTable::get(int key)
{
  int hashValue = hashFunction(key);
  int bucket = hashValue % SIZE;

  if (data[bucket]->key == key)
    return data[bucket]; //best case

  for (int i = bucket+1; i != bucket; i = (i+1) % SIZE) //in case we're dealing with overflow
  {
    if (data[i]->key == key)
      return data[i];
  }
}
////////////////////////////////////////////////////////////////////////////////


int HashTable::hashFunction(int key)
{
  return key % HASHSIZE;
}
////////////////////////////////////////////////////////////////////////////////


int HashTable::findOpenBucket(int startingkey)
{
  int startingKey = startingkey % SIZE;

  if (data[startingKey] == NULL)
    return startingKey;
  else
  {
    for (int i = startingKey+1; i != startingKey; i = (i+1) % SIZE)
    {
      if (data[i] == NULL)
        return i;
    }
    return -1;
  }
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  HashTable mappy;
  mappy.insert(3, 1);
  mappy.insert(5, 3);
  mappy.insert(6, 5);
  mappy.insert(10, 7);
  mappy.insert(14, 9);
  printf("Getting values for 3 and 5:  %d, %d\n", mappy.get(3)->value, mappy.get(5)->value);
  printf("Getting values for 6, 10, 14:  %d, %d, %d\n", mappy.get(6)->value, mappy.get(10)->value, mappy.get(14)->value);
}




