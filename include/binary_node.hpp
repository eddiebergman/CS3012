#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <node_base.hpp>
#include <binary_node_i.hpp>

class BinaryNode : public NodeBase, public BinaryNodeI<BinaryNode>{

    BinaryNode(int id);

public:
    BinaryNode* left() override;
    BinaryNode* right() override;
    BinaryNode* parent() override;
    int depth() override;

private:
    BinaryNode* parent_;
    BinaryNode* left_;
    BinaryNode* right_;

};

#endif //BINARY_NODE_H  