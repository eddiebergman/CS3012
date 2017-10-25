#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <node_base.hpp>
#include <binary_node_i.hpp>

class BinaryNode : public NodeBase, public BinaryNodeI<BinaryNode>{

    
public:

    enum class Child { LEFT, RIGHT };

    using Container = std::unordered_set<BinaryNode*>;
    
    BinaryNode(int id);
    BinaryNode(int id, BinaryNode& parent, Child child_side);
    ~BinaryNode();
    
    int depth() const override;
    void left(BinaryNode& l) override;
    void right(BinaryNode& r) override;
    BinaryNode* left() override;
    BinaryNode* right() override;
    BinaryNode* parent() override;
    bool has_child(BinaryNode& n) override;
    bool has_parent(BinaryNode& n) override;
    Container children() override;
    Container parents() override;

private:
    void adjust_depth(const BinaryNode& new_parent);
    
    int depth_ = 0;
    BinaryNode* parent_ = nullptr;
    BinaryNode* left_ = nullptr;
    BinaryNode* right_ = nullptr;

};

#endif //BINARY_NODE_H  