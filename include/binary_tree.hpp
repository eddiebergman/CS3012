#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <binary_node.hpp>
#include <unordered_set>
#include <vector>

class BinaryTree{

public:
    BinaryTree(BinaryNode& root);
    ~BinaryTree() = default;
    BinaryNode* lca(BinaryNode& one,BinaryNode& two);
    std::unordered_set<BinaryNode*> nodes();
private:
    std::unordered_set<BinaryNode*> nodes_;

};

#endif //BINARY_TREE_H  