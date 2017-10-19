#ifndef DIRECTED_GRAPH_NODE_BASE_H
#define DIRECTED_GRAPH_NODE_BASE_H

#include <node_base.hpp>

class DirectedGraphNodeBase : public NodeBase{

public:
    DirectedGraphNodeBase(int id) : NodeBase(id) {};

    virtual ~DirectedGraphNodeBase() = 0;

    virtual void add_child(DirectedGraphNodeBase* n) = 0;

    virtual bool has_child(DirectedGraphNodeBase* n) = 0;
    virtual bool has_parent(DirectedGraphNodeBase* n) = 0;

};

#endif //DIRECTED_GRAPH_NODE_BASE_H
