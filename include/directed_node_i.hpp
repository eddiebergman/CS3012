#ifndef DIRECTED_NODE_I_H
#define DIRECTED_NODE_I_H

#include <unordered_set>

class DirectedNodeI {

public:
    virtual bool has_child(DirectedNodeI* n) = 0;
    virtual bool has_parent(DirectedNodeI* n) = 0;
    virtual std::unordered_set<DirectedNodeI*>& children() = 0;
    virtual std::unordered_set<DirectedNodeI*>& parents() = 0;

};

#endif //DIRECTED_NODE_I_H