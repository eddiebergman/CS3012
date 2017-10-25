#ifndef BINARY_NODE_I
#define BINARY_NODE_I

#include <tree_node_i.hpp>
#include <unordered_set>

class BinaryNodeI : public TreeNodeI{

public:
    BinaryNodeI* left();
    BinaryNodeI* right();

};

#endif //BINARY_NODE_I