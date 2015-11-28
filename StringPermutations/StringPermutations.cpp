#include <stdio.h>
#include <cstdint>
#include <string>
#include <vector>
#include <set>

using namespace std;

////////////////////////////////////////////////////////////////////////////////


/**
  build a tree of a string
  keep a stack of letters that are available
  insert original word at top of tree
  call recursive function with a string of all the letters in the original word
  
  recursive function:
    for each of the available letters, create a child out of each of the letters:
      recurse with the available letters minus the current node's letter

  do a depth first search of the tree to print out all the string permutations, preorder traversal
  for each child of current node:
    print the node's value
    recurse on the current child node
*/

class treeNode
{
  public:

    treeNode(string val)
      : value(val)
    {
      children = new vector<treeNode*>;
    }
    ~treeNode();

    treeNode * addChild(string value)
    {
      treeNode * childNode = new treeNode(value);
      children->push_back(childNode);
      return childNode;
    }
    
    int numChildren()
    {
      return children->size();
    }

    treeNode * getChild(int i)
    {
      return children->at(i); 
    }
    
    string getValue()
    {
      return value;
    }
    
    void setValue(string val)
    {
      value = val;
    }

  private:

    string value;
    vector<treeNode*> * children = NULL;
};
////////////////////////////////////////////////////////////////////////////////


void createTree(treeNode *& node, string availableLetters)
{
  printf("available letters: %s\n", availableLetters.c_str());
  for (int i = 0; i < availableLetters.size(); i++)
  {
    string nodeValStr;
    nodeValStr.push_back(availableLetters[i]);
    treeNode * childNode = node->addChild(nodeValStr);

    string newAvailableLetters;
    for (int j = 0; j < availableLetters.size(); j++)
    {
      if (j!=i) newAvailableLetters.push_back(availableLetters[j]);
    } 
    printf("letters: %s\n", newAvailableLetters.c_str());
    createTree(childNode, newAvailableLetters);
  }
  //base case is no available letters
}
////////////////////////////////////////////////////////////////////////////////

// void printPermutations(treeNode & node, string permutatedString);


// void printPermutations(treeNode & node)
// {
//   string permutatedString;
//   return printPermutations(node, permutatedString);
// }


void printPermutations(treeNode * node, string permutatedString)
{
  // string newStr = permutatedString;
  printf("node: %s numChildren: %d\n", node->getValue().c_str(), node->numChildren());
  for (int i = 0; i < node->numChildren(); i++)
  {
    // newStr += node->getValue();
    string newstr = "";
    treeNode * nodeptr = node->getChild(i);
    printf("checking child... %s\n", nodeptr->getValue().c_str());
    return printPermutations(nodeptr, newstr);
  }
  // printf("Permutation: %s\n", node->getValue().c_str());

}

void traverse(treeNode * node)
{
  printf("node: %s numChildren: %d\n", node->getValue().c_str(), node->numChildren());
  for (int i = 0; i < node->numChildren(); i++)
  {
    treeNode * nodeptr = node->getChild(i);
    printf("checking child... %s\n", nodeptr->getValue().c_str());
    return traverse(nodeptr);
  }
}

void permuteString(string word)
{
  treeNode * root = new treeNode(word);
  createTree(root, word);
  string newstr;
  printPermutations(root, newstr);
}


int main()
{
  treeNode * root = new treeNode("5");
  treeNode * ptr;
  ptr = root->addChild("4");
  root->addChild("1");
  root->addChild("2");
  root->addChild("3");
  ptr->addChild("2");
  ptr->addChild("3");
  
  string newstr;
  traverse(root);


  // permuteString("abcd");
  return 0;
}
////////////////////////////////////////////////////////////////////////////////

