#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <node_base.hpp>
#include <binary_node_i.hpp>

class BinaryNode : public NodeBase, public BinaryNodeI<BinaryNode>{

    
public:

    using Container = std::unordered_set<BinaryNode*>;
    BinaryNode(int id, BinaryNode* parent = nullptr);
    ~BinaryNode();
    
    int depth() const override;
    bool left(BinaryNode& l) override;
    bool right(BinaryNode& r) override;
    BinaryNode* left() override;
    BinaryNode* right() override;
    BinaryNode& parent() override;
    bool has_child(BinaryNode& n) override;
    bool has_parent(BinaryNode& n) override;
    Container children() override;
    Container parents() override;

private:
    bool deeper(const BinaryNode& other);
    
    BinaryNode* const parent_;
    int depth_;
    BinaryNode* left_ = nullptr;
    BinaryNode* right_ = nullptr;

};

#endif //BINARY_NODE_H  