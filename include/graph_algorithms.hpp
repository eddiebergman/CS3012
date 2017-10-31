#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <directed_node_i.hpp>
#include <functional>
#include <queue>

namespace GraphAlgorithms {

template <typename T>
using USet = std::unordered_set<T>;

template <typename T>
USet<T*> lca(T& a, T& b)
{
    static auto ancestors = [](T& node) {
        std::queue<T*> queue;
        USet<T*> visited;
        visited.insert(&node);
        queue.push(&node);
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

    static auto intersection = [](USet<T*>& a, USet<T*>& b) {
        USet<T*> intersect;
        USet<T*>& smaller_set = a.size() < b.size() ? a : b;
        USet<T*>& larger_set = smaller_set == a ? b : a;
        for (auto node : smaller_set) {
            if (larger_set.find(node) != larger_set.end()) {
                intersect.insert(node);
            }
        }
        return intersect;
    };

    static auto disjoint = [](USet<T*> a, USet<T*>& b) {
        USet<T*>& smaller_set = a.size() < b.size() ? a : b;
        USet<T*>& larger_set = smaller_set == a ? b : a;
        for (auto node : smaller_set) {
            if (larger_set.find(node) != larger_set.end()) {
                return false;
            }
        }
        return true;
    };

    USet<T*> lca_set;
    USet<T*> a_ancestors = ancestors(a);
    USet<T*> b_ancestors = ancestors(b);
    USet<T*> common_ancestors = intersection(a_ancestors, b_ancestors);

    for (auto ancestor : common_ancestors) {
        if (disjoint(ancestor->children(), common_ancestors)) {
            lca_set.insert(ancestor);
        }
    }
    return lca_set;
}

template <typename T>
bool isAcyclic(USet<T*>& graph_nodes)
{
    USet<T*> temp_marked;
    USet<T*> marked;
    bool acyclic = true;

    static auto visit = [&](auto&& self, T* n) -> void {
        if (temp_marked.count(n) == 1 || !acyclic) {
            acyclic = false;
            return;
        }
        if (marked.count(n) == 0) {
            temp_marked.insert(n);
            for (auto child : n->children()) {
                self(self, child);
            }
            marked.insert(n);
            temp_marked.erase(n);
        }
    };

    for (auto node : graph_nodes)
    {
        visit(visit, node);
    }
    return acyclic;
}

};

#endif //GRAPH_ALGORITHMS_H