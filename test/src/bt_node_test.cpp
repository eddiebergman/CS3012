#include <catch.hpp>

#include <iostream>
#include <bt-node.hpp>
#include <string>

SCENARIO("Constructing a BT_Node", "[bt-node]")
{

    GIVEN("An object to copy into the BT_Node")
    {
        const std::string s("copy me");

        WHEN("The BT_Node is constructed with the copy constructor")
        {
            BT_Node<std::string> n(s);

            THEN("The BT_Node will have copied the object ")
            {
                REQUIRE(s == "copy me");
                REQUIRE(n.get() == "copy me");
            }

            THEN("The BT_Node will have 0 depth and no parent")
            {
                REQUIRE(n.depth() == 0);
                REQUIRE(!n.parent());
            }
        }
    }

    GIVEN("An object to move into the BT_Node")
    {
        std::string s("move me");

        WHEN("The BT_Node is constructed with the move constructor")
        {
            BT_Node<std::string> n(std::move(s));

            THEN("The BT_Node will have moved the copied object")
            {
                REQUIRE(s.empty());
                REQUIRE(n.get() == "move me");
            }

            THEN("The BT_Node will have 0 depth and no parent")
            {
                REQUIRE(n.depth() == 0);
                REQUIRE(!n.parent());
            }
        }
    }

    GIVEN("An already constructed BT_Node")
    {
        BT_Node<int> n(10);

        WHEN("A new BT_Node is created on its right using move constructor")
        {
            n.right(20);

            THEN("The BT_Node should be created with the correct data")
            {
                REQUIRE(n.right()->get());
                REQUIRE(n.right()->get() == 20);
                REQUIRE(n.right()->depth() == 1);
                REQUIRE(n.right()->parent() == &n);
            }
        }

        WHEN("A new BT_Node is created on its left using move constructor")
        {
            n.left(30);
            THEN("The BT_Node should be created with the correct data")
            {
                REQUIRE(n.left()->get());
                REQUIRE(n.left()->get() == 30);
                REQUIRE(n.left()->depth() == 1);
                REQUIRE(n.left()->parent() == &n);
            }
        }

        WHEN("A new BT_Node is created on its right using copy constructor")
        {
            const int i = 20;
            n.right(i);

            THEN("The BT_Node should be created with the correct data")
            {
                REQUIRE(n.right()->get());
                REQUIRE(n.right()->get() == 20);
                REQUIRE(n.right()->depth() == 1);
                REQUIRE(n.right()->parent() == &n);
            }
        }

        WHEN("A new BT_Node is created on its left using copy constructor")
        {
            const int i = 30;
            n.left(i);

            THEN("The BT_Node should be created with the correct data")
            {
                REQUIRE(n.left()->get());
                REQUIRE(n.left()->get() == 30);
                REQUIRE(n.left()->depth() == 1);
                REQUIRE(n.left()->parent() == &n);
            }
        }   
    }

    GIVEN("A BT_Node with no BT_Nodes on its left or right")
    {
        BT_Node<int> n(20);
        WHEN("Asked for its left or right noed")
        {
            BT_Node<int>* l = n.left();
            BT_Node<int>* r = n.right();
            
            THEN("It should return both null pointers")
            {
                REQUIRE(!l);
                REQUIRE(!r);
            }
        }
    }
}

SCENARIO("BT_Node memory management tests", "[bt-node]")
{
    GIVEN("Given a constructed BT_Node and its branches")
    {
        BT_Node<int> n(10);
        n.left(20)->left(30);
        n.left()->right(35);
        BT_Node<int>* nl = n.left();
        BT_Node<int>* nll = n.left()->left();
        BT_Node<int>* nlr = n.left()->right();
        WHEN("One of its branches is reassigned")
        {
            n.left(40)->left(50);
            n.left()->right(60);

            // note: we can still use nl and nll without their branches but they're
            // no longer reserved in memory or stack
            THEN("The old branches should be free")
            {
                // left BT_Node no longer had references to any other BT_Node
                REQUIRE(n.left()->left() != nll);
                REQUIRE(n.left()->right() != nlr);
            }
        }
    }
}