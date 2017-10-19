#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <bt-node.hpp>

template <typename T>
class BinaryTree {

public:
    BinaryTree(const T& data)
        : root_(std::make_unique<BT_Node<int>>(data))
    {
    }

    BinaryTree(T&& data)
        : root_(std::make_unique<BT_Node<int>>(std::move(data)))
    {
    }

    BT_Node<T>* lca(BT_Node<T>* const a, BT_Node<T>* const b)
    {
        if (a == nullptr || b == nullptr)
            return nullptr;

        static auto climb = [](BT_Node<T>*& n){ n = n->parent(); };
        static auto lower_of = [](BT_Node<T>*& c1, BT_Node<T>*& c2) -> BT_Node<T>*& { return c1->depth() > c2->depth() ? c1 : c2; };
        static auto at_root = [](BT_Node<T>*& c1, BT_Node<T>*& c2) -> bool { return c1->depth() == 0 && c2->depth() == 0; };
        static auto at_same = [](BT_Node<T>*& c1, BT_Node<T>*& c2) -> bool { return c1 == c2; };

        BT_Node<T>* a_climber = a;
        BT_Node<T>* b_climber = b;

        while (!at_same(a_climber, b_climber) && !at_root(a_climber, b_climber))
            climb(lower_of(a_climber, b_climber));

        return at_same(a_climber, b_climber)
            ? a_climber //they both reached the same spot
            : nullptr; //they reached the root and never matched
    }

    BT_Node<T>& root() { return *root_; }

private:
    std::unique_ptr<BT_Node<T>> root_;
};

#endif //BINARY_TREE_H