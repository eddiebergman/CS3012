#ifndef BT_Node_H
#define BT_Node_H

#include <memory>
#include <node.hpp>

class BTNode : protected Node {

public:
    BTNode(int id);
    ~BTNode() = default;

    BTNode(BTNode &&) = delete;
    BTNode(const BTNode &) = delete;
    BTNode &operator=(BTNode &&) = delete;
    BTNode &operator=(const BTNode &) = delete; 

    int id();
    void left(BTNode *n);
    void right(BTNode *n);
    Node* left();
    Node* right();

}

#endif // BT_Node_H
