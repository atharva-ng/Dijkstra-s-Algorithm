#ifndef _NODE_
#define _NODE_

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

class node
{
public:
  node *parent = nullptr;
  int visited{};
  int obs{1};
  // int push{};
  pair<int, int> position;
  pair<int, int> positionF;
  float cost{9999999};

  node(pair<int, int> positioni)
      : position(positioni)
  {
  }
  node(node *parenti, pair<int, int> positioni, float costi)
      : parent(parenti), position(positioni), cost(costi)
  {
  }

  float findCost(node parent,pair<int, int> positionF)
  {
    int tempCost{};
    tempCost = parent.cost + (sqrt(static_cast<float>(pow((parent.position.first - position.first), 2) + pow((parent.position.second - position.second), 2))))+(sqrt(static_cast<float>(pow((positionF.first - position.first), 2) + pow((positionF.second - position.second), 2))));
    if (tempCost < cost)
    {
      cost = tempCost;
    }
    return cost;
  }

  bool operator>(const node &rhs) const
  {
    if (this->cost > rhs.cost)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator<(const node &rhs) const
  {
    if (this->cost < rhs.cost)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator==(node &rhs) const
  {
    if (this->position == rhs.position)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool operator!=(node &rhs) const
  {
    if (this->position != rhs.position)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

#endif //_NODE_