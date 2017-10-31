#include <binary_node.hpp>

BinaryNode::BinaryNode(int id)
    : NodeBase(id)
{
}

int BinaryNode::id() const {
    return NodeBase::id();
}

BinaryNode::BinaryNode(int id, BinaryNode& parent, Child child_side)
    : NodeBase(id)
    , depth_(parent.depth() + 1)
    , parent_(&parent)
{
    if (child_side == Child::LEFT)
        parent.left(*this);
    else
        parent.right(*this);
}

BinaryNode::~BinaryNode() = default;

int BinaryNode::depth() const
{
    return depth_;
}

void BinaryNode::left(BinaryNode& l)
{
    left_ = &l;
    left_->parent_ = this;
    left_->adjust_depth(*this, *this);
}

void BinaryNode::right(BinaryNode& r)
{
    right_ = &r;
    right_->parent_ = this;
    right_->adjust_depth(*this, *this);
}

BinaryNode* BinaryNode::left()
{
    return left_;
}

BinaryNode* BinaryNode::right()
{
    return right_;
}

BinaryNode* BinaryNode::parent()
{
    return parent_;
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
    Container c;
    if (left_)
        c.insert(left_);
    if (right_)
        c.insert(right_);
    return c;
}

BinaryNode::Container BinaryNode::parents()
{
    return (parent_ ? Container{ parent_ } : Container());
}

void BinaryNode::adjust_depth(const BinaryNode& original_parent, const BinaryNode& new_parent)
{
    if(this == &original_parent){
        throw std::logic_error("Can't make cycle in binary nodes");
    }
    depth_ = new_parent.depth() + 1;
    if (left_)
        left_->adjust_depth(original_parent, *this);
    if (right_)
        right_->adjust_depth(original_parent, *this);
}