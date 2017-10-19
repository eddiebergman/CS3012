#ifndef TREE_NODE_BASE_H
#define TREE_NODE_BASE_H

#include <directed_graph_node_base.hpp>

class TreeNodeBase : public DirectedGraphNodeBase{

public:
    
    TreeNodeBase(int id);
    virtual ~TreeNodeBase() = 0;
    
    int depth() const;
    TreeNodeBase* parent();
    bool has_parent(DirectedGraphNodeBase * n) override;
    
protected:
    
private:
    TreeNodeBase* parent_;
    int depth_;


};

#endif //TREE_NODE_BASE_H