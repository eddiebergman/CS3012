#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <directed_node.hpp>
#include <unordered_set>

class DirectedAcyclicGraph{

public:
    DirectedAcyclicGraph(DirectedNode& graph_node);
    ~DirectedAcyclicGraph() = default;
    std::unordered_set<DirectedNode*> lca(DirectedNode& one,DirectedNode& two);
    std::unordered_set<DirectedNode*> nodes();
private:
    std::unordered_set<DirectedNode*> nodes_;

};

#endif //DIRECTED_GRAPH_H