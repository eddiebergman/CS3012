#ifndef NODE_H
#define NODE_H

#include <set>

class Node
{
public:
    Node(int id);
    ~Node();

    Node(Node &&) = delete;
    Node(const Node &) = delete;
    Node &operator=(Node &&) = delete;
    Node &operator=(const Node &) = delete;

    int id();
    void add_child(Node* n);
    void add_children(std::initializer_list<Node*> ns);
    void add_parent(Node* n);
    void add_parents(std::initializer_list<Node*> ns);
    const std::set<Node*>& parents();
    const std::set<Node*>& children();

protected:

    std::set<Node*> parents_ = std::set<Node*>();
    std::set<Node*> children_ = std::set<Node*>();

private:
    const int id_;
    
};

#endif //NODE_H