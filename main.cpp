#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

using namespace std;

void setGrid(vector<vector<node>> &grid)
{
  {
    // grid.at(1).at(1)=1;
    // grid.at(1).at(2) = 1;
    grid.at(1).at(3).obs = 0;
    // grid.at(1).at(4) = 1;
    // grid.at(1).at(5) = 1;
    // grid.at(1).at(6) = 1;
    // grid.at(1).at(7) = 1;
    // grid.at(1).at(8) = 1;
    // grid.at(2).at(1) = 1;
    // grid.at(2).at(2) = 1;
    grid.at(2).at(3).obs = 0;
    // grid.at(2).at(4) = 1;
    grid.at(2).at(5).obs = 0;
    grid.at(2).at(6).obs = 0;
    grid.at(2).at(7).obs = 0;
    // grid.at(2).at(8) = 1;
    // grid.at(3).at(1) = 1;
    // grid.at(3).at(2) = 1;
    // grid.at(3).at(3) = 1;
    // grid.at(3).at(4) = 1;
    // grid.at(3).at(5) = 1;
    // grid.at(3).at(6) = 1;
    // grid.at(3).at(7) = 1;
    // grid.at(3).at(8) = 1;
    // grid.at(4).at(1) = 1;
    grid.at(4).at(2).obs = 0;
    grid.at(4).at(3).obs = 0;
    grid.at(4).at(4).obs = 0;
    grid.at(4).at(5).obs = 0;
    // grid.at(4).at(6) = 1;
    grid.at(4).at(7).obs = 0;
    // grid.at(4).at(8) = 1;
    // grid.at(5).at(1) = 1;
    // grid.at(5).at(2) = 1;
    // grid.at(5).at(3) = 1;
    // grid.at(5).at(4) = 1;
    // grid.at(5).at(5) = 1;
    // grid.at(5).at(6) = 1;
    // grid.at(5).at(7) = 1;
    // grid.at(5).at(8) = 1;
  }
}

void findNeighbour(vector<node> &emptyNode, vector<vector<node>> &grid, node currentPos)
{
  if (grid.at(currentPos.position.first).at(currentPos.position.second).obs == 1 && grid.at(currentPos.position.first).at(currentPos.position.second).visited == 0)
  {
    for (int hori = -1; hori <= 1; hori++)
    {

      for (int vert = -1; vert <= 1; vert++)
      {
        if (currentPos.position.first + hori > 0 && currentPos.position.first + hori < 6 && currentPos.position.second + vert > 0 && currentPos.position.second + vert < 9)
        {
          if (hori == 0 && vert == 0)
          {
            continue;
          }
          else if (grid.at(currentPos.position.first + hori).at(currentPos.position.second + vert).obs == 1)
          {
            // emptyNodes.(make_pair(currentPos.position.first + hori, currentPos.position.second + vert));
            node temp(make_pair(currentPos.position.first + hori, currentPos.position.second + vert));
            emptyNode.push_back(temp);
          }
        }
      }
    }
  }
}

int main()
{
  vector<vector<node>> grid{
      {node(make_pair(0, 0)), node(make_pair(0, 1)), node(make_pair(0, 2)), node(make_pair(0, 3)), node(make_pair(0, 4)), node(make_pair(0, 5)), node(make_pair(0, 6)), node(make_pair(0, 7)), node(make_pair(0, 8))},
      {node(make_pair(1, 0)), node(make_pair(1, 1)), node(make_pair(1, 2)), node(make_pair(1, 3)), node(make_pair(1, 4)), node(make_pair(1, 5)), node(make_pair(1, 6)), node(make_pair(1, 7)), node(make_pair(1, 8))},
      {node(make_pair(2, 0)), node(make_pair(2, 1)), node(make_pair(2, 2)), node(make_pair(2, 3)), node(make_pair(2, 4)), node(make_pair(2, 5)), node(make_pair(2, 6)), node(make_pair(2, 7)), node(make_pair(2, 8))},
      {node(make_pair(3, 0)), node(make_pair(3, 1)), node(make_pair(3, 2)), node(make_pair(3, 3)), node(make_pair(3, 4)), node(make_pair(3, 5)), node(make_pair(3, 6)), node(make_pair(3, 7)), node(make_pair(3, 8))},
      {node(make_pair(4, 0)), node(make_pair(4, 1)), node(make_pair(4, 2)), node(make_pair(4, 3)), node(make_pair(4, 4)), node(make_pair(4, 5)), node(make_pair(4, 6)), node(make_pair(4, 7)), node(make_pair(4, 8))},
      {node(make_pair(5, 0)), node(make_pair(5, 1)), node(make_pair(5, 2)), node(make_pair(5, 3)), node(make_pair(5, 4)), node(make_pair(5, 5)), node(make_pair(5, 6)), node(make_pair(5, 7)), node(make_pair(5, 8))}};

  setGrid(grid);

  vector<node> emptyNodes;
  findNeighbour(emptyNodes, grid, grid.at(1).at(8).position);

  for (const auto &k : emptyNodes)
  {
    cout << k.position.first << " " << k.position.second << endl;
  }

  return 0;
}
