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
        std::queue<DNode<T>*> queue;
        USet<DNode<T>*> visited;
        visited.insert(node);
        queue.push(node);
        for (auto n = queue.front(); !queue.empty(); queue.pop(), n = queue.front()) {
            for (auto parent : n->parents()) {
                if (visited.find(parent) != visited.end()) {
                    visited.insert(parent);
                    queue.push(parent);
                }
            }
        }
        return visited;
    };

    static auto intersection = [](USet<DNode<T>*> a, USet<DNode<T>*> b) {
        USet<DNode<T>*> intersect;
        USet<DNode<T>*>& smaller_set = a.size() < b.size() ? a : b;
        USet<DNode<T>*>& larger_set = smaller_set == a ? b : a;
        for (auto node : smaller_set) {
            if (larger_set.find(node) != larger_set.end()) {
                intersect.insert(node);
            }
        }
        return intersect;
    };

    static auto disjoint = [](USet<DNode<T>*> a, USet<DNode<T>*> b) {
        USet<DNode<T>*>& smaller_set = a.size() < b.size() ? a : b;
        USet<DNode<T>*>& larger_set = smaller_set == a ? b : a;
        for (auto node : smaller_set) {
            if (larger_set.find(node) != larger_set.end()) {
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

template <typename T>
bool isAcyclic(vector<DNode<T>*> graph_nodes)
{
    USet<DNode<T>*> temp_marked;
    USet<DNode<T>*> marked;
    bool acyclic = true;

    static auto visit = [&](DNode<T>* n) {
        if (temp_marked.count(n) == 1 || !acyclic) {
            acyclic = false;
            return;
        }
        if (marked.count(n) == 0) {
            temp_marked.insert(n);
            for (auto child : n->children()) {
                visit(child);
            }
            marked.insert(n);
            temp_marked.erase(n);
        }
    }

    for (auto node : graph_nodes)
    {
        visit(n);
    }
    return acyclic;
}

};

#endif //GRAPH_ALGORITHMS_H