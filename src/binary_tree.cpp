#include <binary_tree.hpp>
#include <graph_algorithms.hpp>
#include <algorithm>
#include <queue>

BinaryTree::BinaryTree(BinaryNode& root){
    std::queue<BinaryNode*> queue;
    queue.push(&root);
    for(auto node = queue.front(); !queue.empty(); queue.pop(),node = queue.front()){
        nodes_.insert(node);
        for(auto child : node->children()){
            queue.push(child);
        }
    }
}

BinaryNode* lca(BinaryNode* const a, BinaryNode* const b)
{
    if (a == nullptr || b == nullptr)
        return nullptr;

    static auto climb = [](BinaryNode*& n){ n = n->parent(); };
    static auto lower_of = [](BinaryNode*& c1, BinaryNode*& c2) -> BinaryNode*& { return c1->depth() > c2->depth() ? c1 : c2; };
    static auto at_root = [](BinaryNode*& c1, BinaryNode*& c2) -> bool { return c1->depth() == 0 && c2->depth() == 0; };
    static auto at_same = [](BinaryNode*& c1, BinaryNode*& c2) -> bool { return c1 == c2; };

    BinaryNode* a_climber = a;
    BinaryNode* b_climber = b;

    while (!at_same(a_climber, b_climber) && !at_root(a_climber, b_climber))
        climb(lower_of(a_climber, b_climber));

    return at_same(a_climber, b_climber)
        ? a_climber //they both reached the same spot
        : nullptr; //they reached the root and never matched
}