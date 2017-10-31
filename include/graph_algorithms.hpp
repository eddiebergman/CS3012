#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <directed_node_i.hpp>
#include <functional>
#include <queue>

namespace GraphAlgorithms {

template <typename T>
using USet = std::unordered_set<T>;

template <typename T>
using DNode = DirectedNodeI<T>;

template <typename T>
USet<DNode<T>*> lca(DNode<T>* a, DNode<T>* b)
{
    static auto ancestors = [](DNode<T>* node) {
        std::queue<DNode*> queue;
        USet<DNode*> visited;
        visited.insert(node);
        queue.push(node);
        for(auto n = queue.front(); !queue.empty(); queue.pop(), n = queue.front()){
            for(auto parent : n.parents()){
                if(visited.find(parent) != visited.end()){
                    visited.insert(parent);
                    queue.push(parent);
                }
            }
        }
        return visited;
    };

    static auto intersection = [](USet<DNode<T>*> a, USet<DNode<T>*> b) {
        USet<DNode*> intersect;
        USet<DNode*>& smaller_set = a.size() < b.size()? a : b;
        USet<DNode*>& larger_set = smaller_set == a? b : a;
        for(auto node : smaller_set){
            if(larger_set.find(node) != larger_set.end()){
                intersect.insert(node);
            }
        }
        return intersect;
    };

    static auto disjoint = [](USet<DNode<T>*> a, USet<DNode<T>*> b) {
        USet<DNode*>& smaller_set = a.size() < b.size()? a : b;
        USet<DNode*>& larger_set = smaller_set == a? b : a;
        for(auto node : smaller_set){
            if(larger_set.find(node) != larger_set.end()){
                return false;
            }
        }
        return true;
    };

    USet<DNode<T>*> lca_set;
    USet<DNode<T>*> a_ancestors = ancestors(a);
    USet<DNode<T>*> b_ancestors = ancestors(b);
    USet<DNode<T>*> common_ancestors = intersection(a_ancestors, b_ancestors);

    for (auto ancestor : common_ancestors) {
        if (disjoint(ancestor->children(), common_ancestors())) {
            lca_set.insert(ancestor);
        }
    }
    return lca_set;
}
};

#endif //GRAPH_ALGORITHMS_H