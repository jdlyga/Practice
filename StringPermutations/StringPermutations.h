#include <string>
#include <vector>
#include <deque>

class treeNode
{
  public:

    treeNode();
    treeNode(const std::string & val);
    ~treeNode();

    inline void addChild(treeNode * node);
    inline int numChildren();
    treeNode * getChild(const int & i);
    inline std::string getValue();
    inline void setValue(const std::string & val);

    static void traverse(treeNode * node);

  private:

    std::string value;
    std::vector<treeNode*> children;
};
////////////////////////////////////////////////////////////////////////////////


class stringPermutations
{
  public:

    void permuteString(std::string word);

  private:

    void createTree(treeNode * node, std::string & availableLetters);
    void printPermutations(treeNode * root);
    void printPermutations(treeNode * node, std::string builderStr, std::deque<std::string> & stringPermutations);
};
////////////////////////////////////////////////////////////////////////////////
