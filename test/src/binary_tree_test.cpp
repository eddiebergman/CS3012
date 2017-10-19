#include <catch.hpp>

#include <binary_tree.hpp>
#include <iostream>
#include <memory>
#include <bt-node.hpp>

SCENARIO("Setting up a binary tree" , "[binary_tree]")
{

    GIVEN("A tree with its root set with move constructor")
    {
        BinaryTree<int> bt(10);

        WHEN("BT_Nodes are added to the left and right of the root with moving of data")
        {
                        bt.root().left(20);
            bt.root().right(30);

            THEN("The BT_Nodes correctly instansiated in the tree")
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

        WHEN("BT_Nodes are added to the left and right of the root with copying of data")
        {
            bt.root().left(i2);
            bt.root().right(i3);

            THEN("The BT_Nodes correctly instansiated in the tree")
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
        
        BT_Node<int>* two  = b.root().left();
        BT_Node<int>* nine = two->right()->right();
        BT_Node<int>* eight= two->left()->left();
        BT_Node<int>* four = two->left();
        BT_Node<int>* six  = b.root().right()->right();

        WHEN("lca called on two BT_Nodes in the tree")
        {
            BT_Node<int>* r89 = b.lca(eight, nine);
            BT_Node<int>* r49 = b.lca(four, nine);
            BT_Node<int>* r61 = b.lca(six, &b.root());
            BT_Node<int>* r11 = b.lca(&b.root(), &b.root());
            BT_Node<int>* r66 = b.lca(six, six);
            THEN("lca should return their lowest common ancestor")
            {
                REQUIRE(r89->get() == two->get());
                REQUIRE(r49 == two);
                REQUIRE(r61 == &b.root());
                REQUIRE(r11 == &b.root());
                REQUIRE(r66 == six);                
            }
        }

        WHEN("lca called on one BT_Node not contained in the tree")
        {
            BT_Node<int> other1(1);
            BT_Node<int>* r10other1 = b.lca(eight, &other1);

            THEN("lca should return nullptr")
            {
                REQUIRE(r10other1 == nullptr);
            }
        }
        
        WHEN("lca called on two BT_Nodes not contained in the tree")
        {
            BT_Node<int> other1(1);
            BT_Node<int> other2(2);
            BT_Node<int>* rother1other2 = b.lca(&other1, &other2);

            THEN("lca should return nullptr")
            {
                REQUIRE(rother1other2 == nullptr);
            }
        }

        WHEN("lca called with a nullptr")
        {
            BT_Node<int>* blank1 = six->right();
            BT_Node<int>* blank2 = nine->left();
            BT_Node<int>* r8blank1 = b.lca(eight, blank1);
            BT_Node<int>* rblank1blank2 = b.lca(blank1, blank2);

            THEN("lca should return nullptr")
            {
                REQUIRE(rblank1blank2 == nullptr);
                REQUIRE(r8blank1 == nullptr);
            }
        }
    }
}