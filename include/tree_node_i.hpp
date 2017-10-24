#ifndef TREE_NODE_I_H
#define TREE_NODE_I_H

#include <directed_node_i.hpp>
#include <unordered_set>

class TreeNodeI : public DirectedNodeI {

public:
    virtual int depth() = 0;
    virtual TreeNodeI* parent() = 0;

};

#endif //TREE_NODE_I_H