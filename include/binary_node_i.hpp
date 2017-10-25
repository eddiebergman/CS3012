#ifndef BINARY_NODE_I
#define BINARY_NODE_I

#include <tree_node_i.hpp>
#include <unordered_set>

template <typename Implementor>
class BinaryNodeI : public virtual TreeNodeI<Implementor>{

public:
    virtual Implementor* left() = 0;
    virtual Implementor* right() = 0;

};

#endif //BINARY_NODE_I