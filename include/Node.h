#ifndef NODE_H
#define NODE_H

#include <iostream>  // 包含输入输出流
#include <optional>

#define ROW 3
#define COL 3

struct Node {
    int content[ROW][COL]; // 数据成员
    int r;
    int c;
    Node* parent;

    // 构造函数声明
    Node();

    // 成员函数声明
    void print();
    void set_value(int row, int col, int value, Node* p=nullptr);
    Node* up();
    Node* left();
    Node* right();
    Node* down();

    bool operator==(const Node& other) const;
    bool operator!=(const Node& other) const;
    bool operator<(const Node& other) const;

};


#endif // NODE_H
