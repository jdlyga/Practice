#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


class treeNode
{
  public:

    treeNode();
    treeNode(const string & val);
    ~treeNode();

    inline void addChild(treeNode * node);
    inline int numChildren();
    treeNode * getChild(const int & i);
    inline string getValue();
    inline void setValue(const string & val);

    static void traverse(treeNode * node);

  private:

    string value;
    vector<treeNode*> children;
};
////////////////////////////////////////////////////////////////////////////////


class stringPermutations
{
  public:

    void permuteString(string alphabet, string word);

  private:

    void createTree(treeNode * node, string & availableLetters, const int & numSpots, int depth = 1);
    void printPermutations(const string & testStr, treeNode * root);
    void printPermutations(const string & testStr, treeNode * node, string builderStr, int & permutationCounter);
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


/**
  build a tree of a string
  keep a stack of letters that are available
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


void stringPermutations::permuteString(string alphabet, string word)
{
  treeNode root(alphabet);
  createTree(&root, alphabet, word.size());
  printPermutations(word, &root);
}
///////////////////////////////////////////////////////////////////////////////


void stringPermutations::createTree(treeNode * node, string & availableLetters, const int & maxSpots, int depth)
{
  //printf("available letters: %s\n", availableLetters.c_str());
  for (int i = 0; i < availableLetters.size(); i++)
  {
    //printf("current letter: %c\n", availableLetters[i]);
    string nodeValStr;
    nodeValStr.push_back(availableLetters[i]);

    treeNode * childNode = new treeNode();
    childNode->setValue(nodeValStr);
    node->addChild(childNode);

    //printf("letters: %s\n", availableLetters.c_str());
    if (depth < maxSpots)
      createTree(childNode, availableLetters, maxSpots, depth + 1);
  }
  //base case is no available letters
}
///////////////////////////////////////////////////////////////////////////////


void stringPermutations::printPermutations(const string & testStr, treeNode * root)
{
  int permutationCounter = 0;
  for (size_t i = 0; i < root->numChildren(); i++)
  {
    string builderString;
    printPermutations(testStr, root->getChild(i), builderString, permutationCounter);
  }
  printf("%d\n", permutationCounter);
}
////////////////////////////////////////////////////////////////////////////////


void stringPermutations::printPermutations(const string & testStr, treeNode * node, string builderStr, int & permutationCounter)
{
  builderStr += node->getValue();

  for (size_t i = 0; i < node->numChildren(); i++)
  {
    printPermutations(testStr, node->getChild(i), builderStr, permutationCounter);
  }

  if (node->numChildren() == 0)
  {
    if (builderStr < testStr)
    {
      // printf("string: %s\n", builderStr.c_str());
      permutationCounter++;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



bool validate(const string & s)
{
    for(int i = 0; i < s.length(); i++)
    {
      //printf("s[i]: %c\n", s[i]);
        if(s[i] < 'a' || s[0] > 'z')
        {
          //printf("failed at %c\n", s[i]);
            return false;
        }
    }
    
    return true;
}

void sort(string * s)
{
    for(int i = 1; i < s->length(); i++)
    {
        int j = i;
        char a = (*s)[j-1];
        char b = (*s)[j];
        
        while(j > 0 && (*s)[j-1] > (*s)[j])
        {
            char tmp = (*s)[j - 1];
            (*s)[j - 1] = b;
            (*s)[j] = tmp;
            j--;
        }
    }
}

void uniq(string * s)
{
    char t[26] = {0};
    
    for(int i = 0; i < s->length(); i++)
    {
        char c = (*s)[i];
        t[(c - 'a')] = 1;
    }
    
    *s = "";
    
    for(int i = 0; i < 26; i++)
    {
        if(t[i] != 0)
        {
            *s += (i + 'a');
        }
    }
}

//this is pretty slow which is why we're failing the test case.  We can do better using a tree of letters and doing the same test
void genperms(
    int & counter, 
    const string & p, 
    int nextIndex, 
    const string & s, 
    const string & alphabet)
{
    char next = s[nextIndex];
    
    for(int i = 0; i < alphabet.length(); i++)
    {
        char c = alphabet[i];
        
        string px = p + c;
        
        if(px.length() < s.length())
        {
            genperms(counter, px, nextIndex + 1, s, alphabet);
        }
        else
        {
            if(px < s)
            {
              printf("px: %s\n", px.c_str());
                counter++;
            }
        }
    }
}

int main()
{
  string s;
  
  getline(cin, s);
    
  if(validate(s) != true)
  {
    cout << s << endl;
    cout << "-1" << endl;
    return 0;
  }
    
  string alphabet = s;
  int counter = 0;
  
  sort(&alphabet);
  uniq(&alphabet);

  stringPermutations permuter;
  permuter.permuteString(alphabet, s);
  return 0;
}
