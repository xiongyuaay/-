#include "../include/BFS.h"
#include "../include/Node.h"
#include "Astar.h"

/*
2 8 3
1 -1 4
7 6 5
1 2 3
8 -1 4
7 6 5

2 8 3
1 -1 4
7 6 5
2 4 3
1 8 -1
7 6 5   

3 2 5
4 1 8
-1 7 6
1 2 3
4 5 6
7 8 -1

1 2 3
4 5 6
7 8 -1
1 2 3
-1 4 6
7 5 8

2 8 3
1 6 4
7 -1 5
1 2 3
8 -1 4
7 6 5


*/


int main()
{
    BFS solution;
    solution.FindPath();
    solution.Print();
    Astar solution2;
    solution2.FindPath();
    solution2.Print();
    return 0;
}