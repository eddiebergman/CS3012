#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <node.hpp>

template <typename T>
class BinaryTree{

public:
    BinaryTree(T&& data)
        : root_(std::make_unique<Node<int>>(std::move(data))) {}

    Node<T>& root() { return *root_; }

    Node<T>* lca(const Node<T>* a, const Node<T>* b){
        if(a == nullptr || b == nullptr) //who you tryna fool
            return nullptr;
        
        //hopefully these get inlined @optimizer.... but also yay for functional programming
        static auto climb   = [](Node<T>* n)                { n = n->parent(); };
        static auto lower_of= [](Node<T>* c1, Node<T>* c2)  { return c1->depth() < c2->depth? c1 : c2; };
        static auto at_root = [](Node<T>* c1, Node<T>* c2)  { return c1->depth() == 0 && c2->depth() == 0; };
        static auto at_same = [](Node<T>* c1, Node<T>* c2)  { return c1 == c2;};

        Node<T>* a_climber = a;
        Node<T>* b_climber = b;

        while(!at_same(a_climber, b_climber) && !at_root(a_climber, b_climber)) 
            climb(lower_of(a_climber, b_climber));

        return at_same(a_climber, b_climber)
            ? a_climber //they both reached the same spot
            : nullptr; //they reached the root and never matched
    }

private:
    std::unique_ptr<Node<T>> root_;
};

#endif //BINARY_TREE_H