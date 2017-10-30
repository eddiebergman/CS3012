#ifndef DIRECTED_NODE_H
#define DIRECTED_NODE_H

#include <node_base.hpp>
#include <directed_node_i.hpp>
#include <unordered_set>

class DirectedNode : public NodeBase, public DirectedNodeI<DirectedNode>{

public:

    using Container = std::unordered_set<DirectedNode*>;

    DirectedNode(int id);
    ~DirectedNode();

    int id() const override;
    void add_child(DirectedNode& n);
    void add_parent(DirectedNode& n);
    bool has_child(DirectedNode& n) override;
    bool has_parent(DirectedNode& n) override;
    Container children() override;
    Container parents() override;
    

private:
    Container parents_;
    Container children_;

};

#endif //DIRECTED_NODE_H