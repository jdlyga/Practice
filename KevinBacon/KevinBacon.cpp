#include <stdio.h>
#include <cstdint>
#include <set>
#include <string>
#include <queue>

using namespace std;

class actorNode
{
  public:

    actorNode(string name)
      : name(name)
    {}
    ~actorNode()
    {}

    static void starredTogether(actorNode * node1, actorNode * node2)
    {
      node1->starredWith.insert(node2);
      node2->starredWith.insert(node1);
    }

    string name;
    int baconNumber = -1;
    set<actorNode*> starredWith;
};


int findBaconNumber(actorNode * node, string name)
{
  queue<actorNode*> nodeVisitingQueue;
  nodeVisitingQueue.push(node);
  while (!nodeVisitingQueue.empty())
  {
    actorNode * nodeToCheck = nodeVisitingQueue.front();
    nodeVisitingQueue.pop();
    int currentBaconNumber = nodeToCheck->baconNumber;

    if (nodeToCheck->name == name)
    {
      return nodeToCheck->baconNumber;
    }

    for (actorNode * linkedNode : nodeToCheck->starredWith)
    {
      if (linkedNode->baconNumber == -1) //unvisited
      {
        linkedNode->baconNumber = currentBaconNumber + 1;
        nodeVisitingQueue.push(linkedNode);
      }
    }
  }
  return -1;
}


int main()
{
  actorNode kevinBacon("Kevin Bacon");
  actorNode JamesBobson("James Bobson");
  actorNode willSmith("Will Smith");
  actorNode JoeLyga("Joe Lyga");
  actorNode SamJackson("Sam Jackson");

  actorNode::starredTogether(&kevinBacon, &JamesBobson);
  actorNode::starredTogether(&kevinBacon, &willSmith);
  actorNode::starredTogether(&willSmith, &JoeLyga);
  actorNode::starredTogether(&JoeLyga, &JamesBobson);
  actorNode::starredTogether(&JoeLyga, &SamJackson);

  printf("Joe Lyga to Sam Jackson: %d\n", findBaconNumber(&JoeLyga, "Sam Jackson"));
  kevinBacon.baconNumber = -1;
  JamesBobson.baconNumber = -1;
  willSmith.baconNumber = -1;
  JoeLyga.baconNumber = -1;
  SamJackson.baconNumber = -1;
  printf("Sam Jackson to Kevin Bacon: %d\n", findBaconNumber(&SamJackson, "Kevin Bacon"));
}

