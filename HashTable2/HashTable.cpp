#include <vector>
#include <list>
#include <cstddef>
#include <string>
#include <iostream>

const int HASHSIZE = 10;

class Node
{
  public:

    Node(int key, std::string value) : key(key), value(value) {};
    ~Node() {};

    int key;
    std::string value;
};
////////////////////////////////////////////////////////////////////////////////


class HashTable
{
  public:

    HashTable();
    ~HashTable();

    void insert(int key, std::string value);
    std::string get(int key);

  private:

    int hashFunction(int key) {return key % HASHSIZE;};
    std::vector<std::list<Node*>> nodes;
};
////////////////////////////////////////////////////////////////////////////////


HashTable::HashTable()
{
  nodes.resize(HASHSIZE);
}
////////////////////////////////////////////////////////////////////////////////


HashTable::~HashTable()
{
  for (auto list : nodes)
  {
    for (auto * node : list)
    {
      delete node;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////


void HashTable::insert(int key, std::string value)
{
  int hashVal = hashFunction(key);

  for (auto * node : nodes[hashVal])
  {
    if (node == NULL) continue;
    if (node->value == value)
      return; //already in the hash table
  }

  nodes[hashVal].push_back(new Node(key, value));
  return;
}
////////////////////////////////////////////////////////////////////////////////


std::string HashTable::get(int key)
{
  int hashVal = hashFunction(key);

  for (auto * node : nodes[hashVal])
  {
    if (node == NULL) continue;
    if (node->key == key) 
      return node->value;
  }
  return "";
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


int main()
{
  HashTable hash;
  hash.insert(5, "Banana");
  hash.insert(1, "Panda");
  hash.insert(15, "Sandwich");
  hash.insert(2301, "Salad Dressing");

  std::cout << hash.get(5) << std::endl;
  std::cout << hash.get(1) << std::endl;
  std::cout << hash.get(15) << std::endl;
  std::cout << hash.get(2301) << std::endl;

  return 0;
}


