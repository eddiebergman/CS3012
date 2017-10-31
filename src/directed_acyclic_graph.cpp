#include <directed_acyclic_graph.hpp>
#include <directed_node.hpp>
#include <graph_algorithms.hpp>
#include <unordered_set>
#include <queue>

DirectedAcyclicGraph::DirectedAcyclicGraph(DirectedNode& graph_node){
    std::unordered_set<DirectedNode*> visited;
    std::queue<DirectedNode*> queue;
    queue.push(&graph_node);
    for (DirectedNode *node = queue.front(); !queue.empty(); queue.pop(), node = queue.front()) {
        nodes_.insert(node);
        for (auto child : node->children()) {
            if(visited.count(child) == 0){
                queue.push(child);
                visited.insert(child);
            }
        }
        for (auto parent : node->parents()) {
            if(visited.count(parent) == 0){
                queue.push(parent);
                visited.insert(parent);
            }
        }
    }
    if(!GraphAlgorithms::isAcyclic<DirectedNode>(nodes_)){
        throw std::logic_error("Graph must be acyclic");
    }
}

std::unordered_set<DirectedNode*> DirectedAcyclicGraph::lca(DirectedNode& a, DirectedNode& b){
    return GraphAlgorithms::lca<DirectedNode>(a, b);
}