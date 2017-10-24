#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <unordered_set>
#include <node_base.hpp>


class GraphNode : public NodeBase{

public:

    GraphNode(int id);

    virtual ~GraphNode();
    void connect(GraphNode* n);
    bool is_connected(GraphNode* n);
    std::unordered_set<GraphNode*> connections();

private:

    std::unordered_set<GraphNode*> connected_nodes;


};

#endif //GRAPH_NODE_H