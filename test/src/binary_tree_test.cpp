#include <catch.hpp>

#include <binary_tree.hpp>
#include <binary_node.hpp>
#include <iostream>
/*
//                  0
//                 /  \
//                1    2
//               /\   / \
//              3  4 5   6
//             /  /\    /
//            7  8  9  10
//     */
TEST_CASE("Creating a BinaryTree","[binary_tree]"){
    
    std::vector<BinaryNode> nodes;
    for(int i = 0; i < 11; i++){
        BinaryNode n(i);
        nodes.push_back(n);
    }
    nodes[0].left(nodes[1]);
    nodes[0].right(nodes[2]);
    nodes[1].left(nodes[3]);
    nodes[1].right(nodes[4]);
    nodes[2].left(nodes[5]);
    nodes[2].right(nodes[6]);
    nodes[3].left(nodes[7]);
    nodes[4].left(nodes[8]);
    nodes[4].right(nodes[9]);
    nodes[6].left(nodes[10]);
    SECTION("With a non acyclic setup"){
        BinaryTree tree(nodes[0]);
        for(auto e : tree.nodes())
            std::cout << e->id() << '<n';
        for(auto e : nodes){
            REQUIRE(tree.nodes().count(&e) == 1);
        }
    }
    
    SECTION("With a cyclic setup"){
        nodes[9].left(nodes[0]);
        
        std::logic_error err("false");
        try{
            BinaryTree tree(nodes[0]);
        }catch(const std::logic_error& e){
            err = e;
        }
        REQUIRE(err.what() != "false");
    }
}

TEST_CASE("Lca on Binary Tree","[binary_tree]"){
    std::vector<BinaryNode> nodes;
    for(int i = 0; i < 11; i++){
        BinaryNode n(i);
        nodes.push_back(n);
    }
    nodes[0].left(nodes[1]);
    nodes[0].right(nodes[2]);
    nodes[1].left(nodes[3]);
    nodes[1].right(nodes[4]);
    nodes[2].left(nodes[5]);
    nodes[2].right(nodes[6]);
    nodes[3].left(nodes[7]);
    nodes[4].left(nodes[8]);
    nodes[4].right(nodes[9]);
    nodes[6].left(nodes[10]);
    BinaryTree tree(nodes[0]);
    
    SECTION("On two nodes contained in the tree"){
        BinaryNode* ans = tree.lca(nodes[8], nodes[7]);
        REQUIRE(ans == &nodes[1]);
    }

    SECTION("On one node not contained in the tree"){
        BinaryNode dummy1(-10);
        BinaryNode* ans = tree.lca(dummy1, nodes[7]);
        REQUIRE(ans == nullptr);
    }

    SECTION("On two nodes not contained in the tree"){
        BinaryNode dummy1(-10);
        BinaryNode dummy2(-20);
        BinaryNode* ans = tree.lca(dummy1, dummy2);
        REQUIRE(ans == nullptr);
    }
}