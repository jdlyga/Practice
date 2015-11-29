#include "StringPermutations.h"
using namespace std;

/**
  build a tree of a string
  keep a stack of letters that are available
  insert original word at top of tree
  call recursive function with a string of all the letters in the original word
  
  recursive function:
    for each of the available letters, create a child out of each of the letters:
      recurse with the available letters minus the current node's letter
*/

treeNode::treeNode()
{}
////////////////////////////////////////////////////////////////////////////////


treeNode::treeNode(const string & val)
{
  setValue(val);
}
////////////////////////////////////////////////////////////////////////////////


treeNode::~treeNode()
{
  // for (auto & it : children)
  //   delete it;
}
////////////////////////////////////////////////////////////////////////////////


void treeNode::addChild(treeNode * node)
{
  children.push_back(node);
}
////////////////////////////////////////////////////////////////////////////////


int treeNode::numChildren()
{
  return children.size();
}
////////////////////////////////////////////////////////////////////////////////


treeNode * treeNode::getChild(const int & i)
{
  if (i >= children.size()) 
    return NULL;
  else
    return children.at(i);
}
////////////////////////////////////////////////////////////////////////////////


string treeNode::getValue()
{
  return value;
}
////////////////////////////////////////////////////////////////////////////////


void treeNode::setValue(const string & str)
{
  value = str;
}
////////////////////////////////////////////////////////////////////////////////


void treeNode::traverse(treeNode * node)
{
  printf("nodeval: %s\n", node->getValue().c_str());
  for (size_t i = 0; i < node->children.size(); i++)
  {
    traverse(node->children[i]);
  }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void stringPermutations::permuteString(string word)
{
  treeNode root(word);
  createTree(&root, word);
  printPermutations(&root);
}
///////////////////////////////////////////////////////////////////////////////


void stringPermutations::createTree(treeNode * node, string & availableLetters)
{
  // printf("available letters: %s\n", availableLetters.c_str());
  for (int i = 0; i < availableLetters.size(); i++)
  {
    // printf("current letter: %c\n", availableLetters[i]);
    string nodeValStr;
    nodeValStr.push_back(availableLetters[i]);

    treeNode * childNode = new treeNode();
    childNode->setValue(nodeValStr);
    node->addChild(childNode);

    string newAvailableLetters;
    for (int j = 0; j < availableLetters.size(); j++)
    {
      if (j!=i) newAvailableLetters.push_back(availableLetters[j]);
    } 
    // printf("letters: %s\n", newAvailableLetters.c_str());
    createTree(childNode, newAvailableLetters);
  }
  //base case is no available letters
}
///////////////////////////////////////////////////////////////////////////////


void stringPermutations::printPermutations(treeNode * root)
{
  deque<string> stringPermutations;
  for (size_t i = 0; i < root->numChildren(); i++)
  {
    string builderString;
    printPermutations(root->getChild(i), builderString, stringPermutations);
  }

  for (int i = 0; i < stringPermutations.size(); i++)
  {
    if (i % 8 == 0)
    {
      printf("\n");
    }
    printf("%s ", stringPermutations[i].c_str());
  }
}
////////////////////////////////////////////////////////////////////////////////


void stringPermutations::printPermutations(treeNode * node, string builderStr, deque<string> & stringPermutations)
{
  builderStr += node->getValue();

  for (size_t i = 0; i < node->numChildren(); i++)
  {
    printPermutations(node->getChild(i), builderStr, stringPermutations);
  }

  if (node->numChildren() == 0)
  {
    stringPermutations.push_back(builderStr);
  }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void testMyTree()
{
  treeNode node5("5");
  treeNode node4("4");
  treeNode node1("1");
  treeNode node2("2");
  treeNode node3("3");
  treeNode node9("9");
  treeNode node10("10");

  node5.addChild(&node4);
  node5.addChild(&node1);
  node5.addChild(&node2);
  node5.addChild(&node3);

  node4.addChild(&node9);
  node4.addChild(&node10);

  treeNode::traverse(&node5); 
}
////////////////////////////////////////////////////////////////////////////////


int main()
{
  // testMyTree();
  stringPermutations permuter;
  permuter.permuteString("abc");
  permuter.permuteString("Joe");
  permuter.permuteString("Salad");
  return 0;
}
