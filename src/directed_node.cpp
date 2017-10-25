#include <directed_node.hpp>

DirectedNode::DirectedNode(int id) : NodeBase(id) {}

DirectedNode::~DirectedNode() = default;

void DirectedNode::add_child(DirectedNode& n){
    children_.insert(&n);
}

void DirectedNode::add_parent(DirectedNode& n){
    parents_.insert(&n);
}

bool DirectedNode::has_child(DirectedNode& n){
    return children_.count(&n) == 1;
}

bool DirectedNode::has_parent(DirectedNode& n){
    return parents_.count(&n) == 1;
}

DirectedNode::Container DirectedNode::children(){
    return children_;
}
DirectedNode::Container DirectedNode::parents(){
    return parents_;
}