#ifndef DIRECTED_NODE_I_H
#define DIRECTED_NODE_I_H

#include <unordered_set>

template <typename Implementor, 
    typename Container = std::unordered_set<Implementor*>>
class DirectedNodeI {

public:
    virtual bool has_child(Implementor& n) = 0;
    virtual bool has_parent(Implementor& n) = 0;
    virtual Container children() = 0;
    virtual Container parents() = 0;

};

#endif //DIRECTED_NODE_I_H