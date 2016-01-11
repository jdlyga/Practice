#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:

    Node() {};
    Node(char a) : data(a) {};
    ~Node() {};

    static void insert(string str, Node * node = root);
    static void find(string str);
    static void find(string str, Node * node, bool & hasUnrecognized, string & buffer);

    vector<Node*> children;
    char data;
    static Node * root;
};
////////////////////////////////////////////////////////////////////////////////

Node * Node::root = new Node;


void Node::insert(string str, Node * node)
{
  if (str.size() == 0)
  {
    node->children.push_back(new Node('\0'));
    return;
  }

  for (int i = 0; i < node->children.size(); i++)
  {
    Node * child = node->children[i];
    if (child->data == str[0])
    {
      return insert(str.substr(1, str.size()-1), child);
    }
  }
  node->children.push_back(new Node(str[0]));
  return insert(str.substr(1, str.size()-1), node->children[node->children.size()-1]);
}
////////////////////////////////////////////////////////////////////////////////


void Node::find(string str)
{
  string buffer;
  bool hasUnrecognized = false;
  find(str, root, hasUnrecognized, buffer);
}
////////////////////////////////////////////////////////////////////////////////

void Node::find(string str, Node * node, bool & hasUnrecognized, string & buffer)
{
  // cout << "String: " << str << endl;
  // cout << "Buffer: " << buffer << endl << endl;
  if (str.size() == 0)
  {
    cout << buffer << " ";
    return;
  }

  for (int i = 0; i < node->children.size(); i++)
  {
    Node * child = node->children[i];
    if (child->data == str[0])
    {
      //found a good one so empty the buffer
      if (hasUnrecognized)
      {
        cout << "?" << buffer << "? ";
        buffer = "";
        hasUnrecognized = false;
      }

      buffer += str[0];
      return find(str.substr(1, str.size()-1), child, hasUnrecognized, buffer);
    }
    else if (child->data == '\0')
    {
      cout << buffer << " ";
      node = root;
      buffer = "";
      return find(str, node, hasUnrecognized, buffer);
    }
  }

  node = root;
  buffer += str[0];
  hasUnrecognized = true;
  return find(str.substr(1, str.size()-1), node, hasUnrecognized, buffer);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


int main()
{
  vector<string> V = {"looked", "just", "like", "her", "brother"};
  for (auto str : V)
  {
    Node::insert(str);
  }

  string input = "jessicalookedlikemeandshealsolookedjustliketimherbrother";

  Node::find(input);

  return 0;
}

