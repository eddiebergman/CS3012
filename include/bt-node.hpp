#ifndef BT_Node_H
#define BT_Node_H

#include <memory>

template <typename T>
class BT_Node {

private:
    // Work around for make_unique<>() not having access to private constructors
    // http://rienajouter.blogspot.com.es/2014/10/makeshared-and-makeunique-for-classes.html
    struct private_tag {
    };

public:
    // single only BT_Nodes, can act as roots
    BT_Node(const T& data)
        : BT_Node(nullptr, data, private_tag())
    {
    }

    BT_Node(T&& data)
        : BT_Node(nullptr, std::move(data), private_tag())
    {
    }

    ~BT_Node() = default;

    explicit BT_Node(BT_Node<T>* parent, const T& data, private_tag t)
        : data_(data)
        , parent_(parent)
        , depth_(parent ? parent->depth_ + 1 : 0)
    {
    }

    explicit BT_Node(BT_Node<T>* parent, T&& data, private_tag t)
        : data_(std::forward<T>(data))
        , parent_(parent)
        , depth_(parent ? parent->depth_ + 1 : 0)
    {
    }

    //Explicitly Delete copy and move constructors
    BT_Node(BT_Node<T>&&) = delete;
    BT_Node(const BT_Node<T>&) = delete;
    BT_Node& operator=(BT_Node<T>&&) = delete;
    BT_Node& operator=(const BT_Node<T>&) = delete;

    // copy and move constructors for adding branches to BT_Nodes
    BT_Node<T>* left(const T& data)
    {
        left_ = std::make_unique<BT_Node<T>>(this, data, private_tag());
        return left();
    }

    BT_Node<T>* left(T&& data)
    {
        left_ = std::make_unique<BT_Node<T>>(this, std::move(data), private_tag());
        return left();
    }

    BT_Node<T>* right(const T& data)
    {
        right_ = std::make_unique<BT_Node<T>>(this, data, private_tag());
        return right();
    }

    BT_Node<T>* right(T&& data)
    {
        right_ = std::make_unique<BT_Node<T>>(this, std::move(data), private_tag());
        return right();
    }

    // getters
    int depth() const { return depth_; }
    T& get() { return data_; }
    BT_Node<T>* parent() const { return parent_; }
    BT_Node<T>* left() const { left_? left_.get() : nullptr; }
    BT_Node<T>* right() const { right_? right_.get() : nullptr; }

private:
    T data_;
    BT_Node<T>* const parent_;
    const int depth_;

    std::unique_ptr<BT_Node<T>> left_ = std::unique_ptr<BT_Node<T>>(nullptr);
    std::unique_ptr<BT_Node<T>> right_ = std::unique_ptr<BT_Node<T>>(nullptr);
};

#endif // BT_Node_H
