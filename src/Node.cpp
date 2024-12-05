#include "../include/Node.h"
#include <cstring>  // 用于 memset
#include "Node.h"

// 构造函数定义
Node::Node() 
{
    memset(content, 0, sizeof(content));
    parent = nullptr;
}

// print 函数定义
void Node::print() {
    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < COL; j++) 
        {
            if (content[i][j] == -1)
            {
                std::cout << " " << " ";
                continue;
            }
            
            std::cout << content[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // std::cout << std::endl;
}

// set_value 函数定义
void Node::set_value(int row, int col, int value, Node* p) 
{
    if (row < ROW && row >= 0 && col < COL && col >= 0) 
    {
        if (value == -1)
        {
            r = row;
            c = col;
        }
        
        content[row][col] = value;
    } 
    else 
    {
        std::cerr << "索引超出界限" << std::endl;
    }

    parent = p;

}

Node* Node::up()
{
    if (r-1 >= 0)
    {
        if (this->parent && this->parent->r == r-1)
        {
            return nullptr;
        }
        
        Node* newNode = new Node(*this);
        newNode->content[r][c] = newNode->content[r-1][c];
        newNode->content[r-1][c] = -1;
        newNode->r = r-1;
        newNode->c = c;
        newNode->parent = this;
        return newNode;
    }
    return nullptr;
}

Node* Node::left()
{
    if (c-1 >= 0)
    {
        if (this->parent && this->parent->c == c-1)
        {
            return nullptr;
        }
        Node* newNode = new Node(*this);
        newNode->content[r][c] = newNode->content[r][c-1];
        newNode->content[r][c-1] = -1;
        newNode->r = r;
        newNode->c = c-1;
        newNode->parent = this;
        return newNode;
    }
    return nullptr;
}

Node* Node::right()
{
    if (c+1 < COL)
    {
        if (this->parent && this->parent->c == c+1)
        {
            return nullptr;
        }
        Node* newNode = new Node(*this);
        newNode->content[r][c] = newNode->content[r][c+1];
        newNode->content[r][c+1] = -1;
        newNode->r = r;
        newNode->c = c+1;
        newNode->parent = this;
        return newNode;
    }
    return nullptr;
}

Node* Node::down()
{
    if (r+1 < ROW)
    {
        if (this->parent && this->parent->r == r+1)
        {
            return nullptr;
        }
        Node* newNode = new Node(*this);
        newNode->content[r][c] = newNode->content[r+1][c];
        newNode->content[r+1][c] = -1;
        newNode->r = r+1;
        newNode->c = c;
        newNode->parent = this;
        return newNode;
    }
    return nullptr;
}

bool Node::operator==(const Node &other) const
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (content[i][j] != other.content[i][j])
            {
                return false;
            }
            
        }
        
    }
    
    return true;
}

bool Node::operator!=(const Node &other) const
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (content[i][j] != other.content[i][j])
            {
                return true;
            }
            
        }
        
    }
    
    return false;
}

bool Node::operator<(const Node& other) const
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (content[i][j] != other.content[i][j])
            {
                return content[i][j] < other.content[i][j];
            }
        }
        
    }
    
    return false;
}