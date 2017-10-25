#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <node_base.hpp>
#include <binary_node_i.hpp>

class BinaryNode : public NodeBase, public BinaryNodeI<BinaryNode>{

    BinaryNode(int id, BinaryNode* parent);

public:
    
    int depth() override;
    BinaryNode* left() override;
    BinaryNode* right() override;
    BinaryNode* parent() override;
    bool has_child(BinaryNode* n) override;
    bool has_parent(BinaryNode* n) override;
    std::unordered_set<BinaryNode*>& children();
    std::unordered_set<BinaryNode*>& parents();

private:
    BinaryNode* parent_;
    BinaryNode* left_;
    BinaryNode* right_;

};

#endif //BINARY_NODE_H  