#include <binary_node.hpp>

BinaryNode::BinaryNode(int id, BinaryNode* parent)
    : NodeBase(id)
    , parent_(parent)
    , depth_(parent ? parent->depth() + 1 : 0)
{
}

BinaryNode::~BinaryNode() = default;

int BinaryNode::depth() const
{
    return depth_;
}

bool BinaryNode::left(BinaryNode& l)
{
    return left_ == &l;
}

bool BinaryNode::right(BinaryNode& r)
{
    return right_ == &r;
}

BinaryNode* BinaryNode::left()
{
    return left_;
}

BinaryNode* BinaryNode::right()
{
    return right_;
}

BinaryNode& BinaryNode::parent()
{
    return *parent_;
}

bool BinaryNode::has_child(BinaryNode& n)
{
    return left_ == &n || right_ == &n;
}

bool BinaryNode::has_parent(BinaryNode& n)
{
    return parent_ == &n;
}

BinaryNode::Container BinaryNode::children()
{
    return Container{ left_, right_ };
}


BinaryNode::Container BinaryNode::parents()
{
    return Container{parent_} ;
}