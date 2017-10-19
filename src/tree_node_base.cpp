#include <tree_node_base.hpp>

TreeNodeBase::TreeNodeBase(int id) : DirectedGraphNodeBase(id) {}

TreeNodeBase* TreeNodeBase::parent(){
    return parent_;
}

int TreeNodeBase::depth() const{
    return depth_;
}

bool 
TreeNodeBase::has_parent(DirectedGraphNodeBase* n){
    return parent_ == n;
}