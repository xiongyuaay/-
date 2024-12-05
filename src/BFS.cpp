#include "BFS.h"
#include <queue>
#include <optional>

BFS::BFS()
{
    cout<<"请输入初始节点状态"<<endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int value;
            cin>>value;
            head.set_value(i, j, value);
        }
        
    }
    cout<<"请输入目标节点状态"<<endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int value;
            cin>>value;
            target.set_value(i, j, value);
        }
        
    }
    
}

void BFS::FindPath()
{
    queue<Node*> wait;
    wait.emplace(&head);
    used.insert(head);
    while (!wait.empty())
    {
        Node* curr = wait.front();
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
        if (temp && used.count(*temp) == 0)
        {
            wait.emplace(temp);
            used.insert(*temp);
        }
        temp = curr->left();
        if (temp && used.count(*temp) == 0)
        {
            used.insert(*temp);
            wait.emplace(temp);
        }
        temp = curr->right();
        if (temp && used.count(*temp) == 0)
        {
            used.insert(*temp);
            wait.emplace(temp);
        }
        temp = curr->down();
        if (temp && used.count(*temp) == 0)
        {
            used.insert(*temp);
            wait.emplace(temp);
        }
    }
}

void BFS::Print()
{
    cout<<"处理节点数目："<<used.size()<<endl;
    if (path.empty())
    {
        cout<<"没有从初始节点到目标节点的路径"<<endl;
        return;
    }

    cout<<endl;

    for (int i = path.size()-1; i >= 0; i--)
    {
        path[i].print();
        if (i == 0)
        {
            break;
        }
        
        cout<<" \u2193"<<endl;
    }
    
    
}

bool BFS::NotUsed(Node &node)
{
    return false;
}
