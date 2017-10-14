#include <catch.hpp>

#include <binary_tree.hpp>
#include <iostream>
#include <memory>
#include <node.hpp>

SCENARIO("Setting up a binary tree")
{

    GIVEN("A tree with its root set with move constructor")
    {
        BinaryTree<int> bt(10);

        WHEN("Nodes are added to the left and right of the root with moving of data")
        {
            bt.root().left(20);
            bt.root().right(30);

            THEN("The nodes correctly instansiated in the tree")
            {
                REQUIRE(bt.root().get() == 10);
                REQUIRE(bt.root().left()->get() == 20);
                REQUIRE(bt.root().left()->depth() == 1);
                REQUIRE(bt.root().right()->get() == 30);
                REQUIRE(bt.root().right()->depth() == 1);
            }
        }
    }

    GIVEN("A tree with its root set with copy constructor")
    {
        const int i = 10;
        const int i2 = 20;
        const int i3 = 30;
        BinaryTree<int> bt(i);

        WHEN("Nodes are added to the left and right of the root with copying of data")
        {
            bt.root().left(i2);
            bt.root().right(i3);

            THEN("The nodes correctly instansiated in the tree")
            {
                REQUIRE(bt.root().get() == i);
                REQUIRE(bt.root().left()->get() == i2);
                REQUIRE(bt.root().left()->depth() == 1);
                REQUIRE(bt.root().right()->get() == i3);
                REQUIRE(bt.root().right()->depth() == 1);
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

        WHEN("lca called on one node not contained in the tree")
        {
            THEN("lca should return nullptr")
            {
                REQUIRE(1 == 0);
            }
        }

        WHEN("lca called on two nodes not contained in the tree")
        {
            THEN("lca should return nullptr")
            {
                REQUIRE(1 == 0);
            }
        }

        WHEN("lca called with a nullptr")
        {
            THEN("lca should return nullptr")
            {
                REQUIRE(1 == 0);
            }
        }
    }
}