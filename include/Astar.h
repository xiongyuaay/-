#ifndef ASTAR_H
#define ASTAR_H

#include "./Node.h"
#include "BFS.h"

struct pNode
{
    Node* node;
    int depth;
    int cost;
    pNode(): node(nullptr), depth(0), cost(0) {}
};

struct ComparePNode
{
    bool operator()(const pNode& p1, const pNode& p2) const
    {
        return p1.cost > p2.cost;
    }
};


class Astar: public BFS
{
private:
    vector<pair<int, int>> positions;
public:
    Astar(/* args */);
    void FindPath() override;
    int ManhattanDistance(Node& node);
};


#endif