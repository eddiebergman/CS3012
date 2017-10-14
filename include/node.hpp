#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
class Node{

private:
    //Work around for make_unique<>() not having access to private constructors
    //http://rienajouter.blogspot.com.es/2014/10/makeshared-and-makeunique-for-classes.html
    struct private_tag{};    

public:
    //single only nodes, can act as roots
    Node(const T& data)
        : Node(nullptr, data, private_tag()) {}

    Node(T&& data)
        : Node(nullptr, std::move(data), private_tag()) {}


    ~Node() = default;

    Node(Node<T> &&) = delete;
    Node(const Node<T> &) = delete;
    Node &operator=(Node<T> &&) = delete;
    Node &operator=(const Node<T> &) = delete;

    //see comment @struct private_tag{} at top
    //branch nodes, can only be constructed from a a parent node
    explicit Node(const Node<T>* parent, const T& data, private_tag t) 
        :data_(data), 
        parent_(parent),
        depth_(parent? parent->depth_ + 1 : 0) {}

    explicit Node(const Node<T>* parent, T&& data, private_tag t) 
        :data_(std::forward<T>(data)),
         parent_(parent),
        depth_(parent? parent->depth_ + 1 : 0) {}


    //getters
    int depth() const { return depth_; }
    T& get() { return data_; }
    const Node<T>* parent() const{ return parent_;}
    Node<T>* left() const { left_.get(); }
    Node<T>* right() const { right_.get(); }
    
    //copy and move constructors for adding branches to nodes
    Node<T>* left(const T& data){ 
        left_ = std::make_unique<Node<T>>(this, data, private_tag()); 
        return left();
    } 
    Node<T>* left(T&& data){ 
        left_ = std::make_unique<Node<T>>(this, std::move(data), private_tag()); 
        return left();
    }

    Node<T>* right(const T& data){
        right_ = std::make_unique<Node<T>>(this, data, private_tag());
        return right();
    }
    Node<T>* right(T&& data)   { 
        right_ = std::make_unique<Node<T>>(this, std::move(data), private_tag()); 
        return right();
    }



private:
    const Node<T>* const parent_;
    const int depth_;
    T data_;

    std::unique_ptr<Node<T>> left_ = std::unique_ptr<Node<T>>();
    std::unique_ptr<Node<T>> right_ = std::unique_ptr<Node<T>>();
    
};

#endif //NODE_H
