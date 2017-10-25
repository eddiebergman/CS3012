#ifndef NODE_BASE_H
#define NODE_BASE_H

class NodeBase{

public:

    NodeBase(int id);
    ~NodeBase() = default;

    int id() const;

private:
    const int id_;

};

#endif //NODE_BASE_H