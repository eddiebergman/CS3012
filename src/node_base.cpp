#include <node_base.hpp>

NodeBase::NodeBase(int id) : id_(id) {}

int NodeBase::id() const {
    return id_;
}