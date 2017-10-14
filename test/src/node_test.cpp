#include <catch.hpp>

#include <string>
#include <node.hpp>

SCENARIO("Constructing a node"){

    GIVEN("An object to copy into the node"){
        const std::string s("copy me");

        WHEN("The node is constructed with the copy constructor"){
            Node<std::string> n(s);

            THEN("The node will have copied the object "){
                REQUIRE(s == "copy me");
                REQUIRE(n.get() == "copy me");
            }

            THEN("The node will have 0 depth and no parent"){
                REQUIRE(n.depth() == 0);
                REQUIRE(!n.parent());
            }
        }
    }

    GIVEN("An object to move into the node"){
        std::string s("move me");
        
        WHEN("The node is constructed with the move constructor"){
            Node<std::string> n(std::move(s));
            
            THEN("The node will have moved the copied object"){
                REQUIRE(s.empty());
                REQUIRE(n.get() == "move me");
            }


            THEN("The node will have 0 depth and no parent"){
                REQUIRE(n.depth() == 0);
                REQUIRE(!n.parent());
            }
        }
    }

    GIVEN("An already constructed node"){
        Node<int> n(10);

        WHEN("A new node is created on its right using move constructor"){
            n.right(20);

            THEN("The node should be created with the correct data"){
                REQUIRE(n.right()->get());
                REQUIRE(n.right()->get() == 20);
                REQUIRE(n.right()->depth() == 1);
                REQUIRE(n.right()->parent() == &n);
            }
        }

        WHEN("A new node is created on its left using move constructor"){
            n.left(30);
            THEN("The node should be created with the correct data"){
                REQUIRE(n.left()->get());
                REQUIRE(n.left()->get() == 30);
                REQUIRE(n.left()->depth() == 1);
                REQUIRE(n.left()->parent() == &n);
            }
        }


        WHEN("A new node is created on its right using copy constructor"){
            const int i = 20;
            n.right(i);

            THEN("The node should be created with the correct data"){
                REQUIRE(n.right()->get());
                REQUIRE(n.right()->get() == 20);
                REQUIRE(n.right()->depth() == 1);
                REQUIRE(n.right()->parent() == &n);
            }
        }

        WHEN("A new node is created on its left using copy constructor"){
            const int i = 30;
            n.left(i);
            
            THEN("The node should be created with the correct data"){
                REQUIRE(n.left()->get());
                REQUIRE(n.left()->get() == 30);
                REQUIRE(n.left()->depth() == 1);
                REQUIRE(n.left()->parent() == &n);
            }
        }
    }

}