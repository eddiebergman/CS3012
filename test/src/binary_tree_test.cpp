#include <catch.hpp>

#include <binary_tree.hpp>
#include <iostream>
#include <memory>
#include <node.hpp>

SCENARIO("Setting up a binary tree")
{

    GIVEN("A tree with its root set")
    {
        BinaryTree<int> bt(10);

        WHEN("Nodes are added to the left and right of the tree")
        {
            bt.root().left(20);
            bt.root().right(30);

            THEN("The nodes correctly instansiated in the tree")
            {
                // REQUIRE(bt.root().get() == 10);
                // REQUIRE(bt.root().left()->get() == 20);
                // REQUIRE(bt.root().right()->get() == 30);
            }
        }
    }
}

SCENARIO("Lowest Common Ancestor on a binary tree")
{

    GIVEN("A populated binary tree")
    {

        WHEN("lca called on two nodes in the tree")
        {

            THEN("lca should return their lowest common ancestor")
            {
                REQUIRE(1 == 0);
            }
        }
    }
}