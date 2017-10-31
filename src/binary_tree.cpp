#include <algorithm>
#include <binary_tree.hpp>
#include <graph_algorithms.hpp>
#include <queue>

BinaryTree::BinaryTree(BinaryNode& root)
{
    std::queue<BinaryNode*> queue;
    queue.push(&root);
    for (BinaryNode *node = queue.front(); !queue.empty(); queue.pop(), node = queue.front()) {
        nodes_.insert(node);
        for (auto child : node->children()) {
            if(nodes_.count(child) == 0)
                queue.push(child);
            else
                throw std::logic_error("Tree is malformed");
        
        }
    }
}

std::unordered_set<BinaryNode*> BinaryTree::nodes(){
    return nodes_;
}

BinaryNode* BinaryTree::lca(BinaryNode& a, BinaryNode& b)
{
    std::unordered_set<BinaryNode*> results = GraphAlgorithms::lca<BinaryNode>(a, b);
    return results.empty() ? nullptr : *results.begin();
}