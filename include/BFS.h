#ifndef BFS_H
#define BFS_H

#include "./Node.h"
#include <vector>
#include <set>
using namespace std;

class BFS
{
protected:
    Node head;
    Node target;
    vector<Node> path;
    set<Node> used;

public:
    BFS(/* args */);

    virtual void FindPath();
    void Print();
    bool NotUsed(Node& node);
};





#endif