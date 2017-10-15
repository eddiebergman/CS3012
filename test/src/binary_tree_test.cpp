#include <catch.hpp>

#include <binary_tree.hpp>
#include <iostream>
#include <memory>
#include <node.hpp>

SCENARIO("Setting up a binary tree" , "[binary_tree]")
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

SCENARIO("Lowest Common Ancestor on a binary tree", "[binary_tree]")
{
    /*
                 1
                /  \
               2    3
              /\     \
             4  5     6
            /  /\ 
           8  10 9
    */
    GIVEN("A populated binary tree")
    {
        BinaryTree<int> b(1);
        b.root().left(2)->left(4)->left(8)->parent()->parent()->right(5)->right(9)->parent()->left(10);
        b.root().right(3)->right(6);
        
        Node<int>* two  = b.root().left();
        Node<int>* nine = two->right()->right();
        Node<int>* eight= two->left()->left();
        Node<int>* four = two->left();
        Node<int>* six  = b.root().right()->right();

        WHEN("lca called on two nodes in the tree")
        {
            Node<int>* r89 = b.lca(eight, nine);
            Node<int>* r49 = b.lca(four, nine);
            Node<int>* r61 = b.lca(six, &b.root());
            Node<int>* r11 = b.lca(&b.root(), &b.root());
            Node<int>* r66 = b.lca(six, six);
            THEN("lca should return their lowest common ancestor")
            {
                REQUIRE(r89->get() == two->get());
                REQUIRE(r49 == two);
                REQUIRE(r61 == &b.root());
                REQUIRE(r11 == &b.root());
                REQUIRE(r66 == six);                
            }
        }

        WHEN("lca called on one node not contained in the tree")
        {
            Node<int> other1(1);
            Node<int>* r10other1 = b.lca(eight, &other1);

            THEN("lca should return nullptr")
            {
                REQUIRE(r10other1 == nullptr);
            }
        }
        
        WHEN("lca called on two nodes not contained in the tree")
        {
            Node<int> other1(1);
            Node<int> other2(2);
            Node<int>* rother1other2 = b.lca(&other1, &other2);

            THEN("lca should return nullptr")
            {
                REQUIRE(rother1other2 == nullptr);
            }
        }

        WHEN("lca called with a nullptr")
        {
            Node<int>* blank1 = six->right();
            Node<int>* blank2 = nine->left();
            Node<int>* r8blank1 = b.lca(eight, blank1);
            Node<int>* rblank1blank2 = b.lca(blank1, blank2);

            THEN("lca should return nullptr")
            {
                REQUIRE(rblank1blank2 == nullptr);
                REQUIRE(r8blank1 == nullptr);
            }
        }
    }
}