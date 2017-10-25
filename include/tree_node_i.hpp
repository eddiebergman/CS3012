#ifndef TREE_NODE_I_H
#define TREE_NODE_I_H

#include <directed_node_i.hpp>
#include <unordered_set>

template <typename Implementor>
class TreeNodeI : public virtual DirectedNodeI<Implementor> {

public:
    virtual int depth() const = 0;
    virtual Implementor& parent() = 0;

};

#endif //TREE_NODE_I_H