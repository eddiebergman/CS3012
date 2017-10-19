#include <node.hpp>

Node::Node(int id) : id_(id) {}

int Node::id() { return id_; }

void Node::add_child(Node* n) { children_.insert(n); }

void Node::add_children(std::initializer_list<Node*> ns) 
{ 
    for(auto e: ns){
        children_.insert(e);
    }
}

void Node::add_parent(Node* n) { parents_.insert(n); }

void Node::add_parents(std::initializer_list<Node*> ns)
{
    for(auto e: ns){
        parents_.insert(e);
    }
}

const std::set<Node*>& Node::parents(){
    return parents_;
}

const std::set<Node*>& Node::children(){
    return children_;
}