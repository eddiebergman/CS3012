#include <algorithm>
#include <binary_tree.hpp>
#include <graph_algorithms.hpp>
#include <queue>

BinaryTree::BinaryTree(BinaryNode& root)
    : nodes_()
{
    std::queue<BinaryNode*> queue;
    queue.push(&root);
    for (BinaryNode *node = queue.front(); !queue.empty(); queue.pop(), node = queue.front()) {
        nodes_.insert(node);
        for (auto child : node->children()) {
            queue.push(child);
        }
    }
    if(!GraphAlgorithms::isAcyclic<BinaryNode>(nodes_)){
        throw std::logic_error("Graph is not acyclic");
    }
}

BinaryNode* BinaryTree::lca(BinaryNode& a, BinaryNode& b)
{
    std::unordered_set<BinaryNode*> results = GraphAlgorithms::lca<BinaryNode>(a, b);
    return results.empty() ? nullptr : *results.begin();
}