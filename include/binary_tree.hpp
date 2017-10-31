#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <binary_node.hpp>
#include <unordered_set>

class BinaryTree{

public:
    BinaryTree(BinaryNode& root);
    ~BinaryTree() = default;
    BinaryNode* lca(BinaryNode& one,BinaryNode& two);

};

#endif //BINARY_TREE_H  