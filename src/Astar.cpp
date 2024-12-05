#include "Astar.h"
#include <queue>
#include <utility>
#include <cmath>

Astar::Astar()
{
    positions.resize(ROW * COL);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0;j < COL;j++)
        {
            if (target.content[i][j] == -1)
            {
                positions[0] = make_pair(i, j);
                continue;
            }
            positions[target.content[i][j]] = make_pair(i, j);
        }
    }
}

void Astar::FindPath()
{
    priority_queue<pNode, vector<pNode>, ComparePNode> wait;
    pNode h;
    h.node = &head;
    h.depth = 0;
    h.cost = ManhattanDistance(head) + h.depth;
    wait.emplace(h);
    used.insert(head);
    while (!wait.empty())
    {
        pNode c = wait.top();
        Node* curr = c.node;
        wait.pop();

        if (*curr == target)
        {
            path.emplace_back(*curr);
            while (path.back().operator!=(head))
            {
                path.emplace_back(*(path.back().parent));
            }
            break;
        }
        Node* temp = curr->up();
        pNode newpNode;
        if (temp && used.count(*temp) == 0)
        {
            newpNode.depth = c.depth+1;
            newpNode.cost = ManhattanDistance(*temp) + newpNode.depth;
            newpNode.node = temp;
            wait.emplace(newpNode);
            used.insert(*temp);
        }
        temp = curr->left();
        if (temp && used.count(*temp) == 0)
        {
            newpNode.depth = c.depth+1;
            newpNode.cost = ManhattanDistance(*temp) + newpNode.depth;
            newpNode.node = temp;
            wait.emplace(newpNode);
            used.insert(*temp);
        }
        temp = curr->right();
        if (temp && used.count(*temp) == 0)
        {
            newpNode.depth = c.depth+1;
            newpNode.cost = ManhattanDistance(*temp) + newpNode.depth;
            newpNode.node = temp;
            wait.emplace(newpNode);
            used.insert(*temp);
        }
        temp = curr->down();
        if (temp && used.count(*temp) == 0)
        {
            newpNode.depth = c.depth+1;
            newpNode.cost = ManhattanDistance(*temp) + newpNode.depth;
            newpNode.node = temp;
            wait.emplace(newpNode);
            used.insert(*temp);
        }
    }
}

int Astar::ManhattanDistance(Node &node)
{
    int cost = 0;
    for (int i = 0; i < ROW; i++)
    {
        for(int j=0;j<COL;j++)
        {
            int curr = node.content[i][j];
            if (curr == -1)
            {
                continue;
            }
            
            cost += abs(i - positions[curr].first) + abs(j - positions[curr].second);
        }
    }
    return cost;
}
