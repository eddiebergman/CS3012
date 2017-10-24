#ifndef DIRECTED_NODE_H
#define DIRECTED_NODE_H

#include <node_base.hpp>
#include <unordered_set>

class DirectedNode : public NodeBase{

    using Node_Set = std::unordered_set<DirectedNode*>;

public:
    DirectedNode(int id);
    ~DirectedNode();

    void add_child(DirectedNode* n);
    void add_parent(DirectedNode* n);
    bool has_child(DirectedNode* n);
    bool has_parent(DirectedNode* n);
    Node_Set& children();
    Node_Set& parents();
    

private:
    Node_Set parents_;
    Node_Set children_;

};

#endif //DIRECTED_NODE_H