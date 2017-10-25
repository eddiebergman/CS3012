#include <binary_node.hpp>
#include <catch.hpp>

TEST_CASE("Binary Node Construction", "[binary_node][node]")
{

    SECTION("Node construction with no parent")
    {
        BinaryNode n(1);
        REQUIRE(n.id() == 1);
    }

    SECTION("Node construction with parent")
    {
        BinaryNode parent_node(2);
        BinaryNode n(1, parent_node, BinaryNode::Child::LEFT);
        REQUIRE(parent_node.left() == &n);
        REQUIRE(n.parent() == &parent_node);
        REQUIRE(n.depth() == parent_node.depth() + 1);
    }
}

TEST_CASE("Binary Node children methods", "[binary_node][node]")
{

    BinaryNode parent(1);
    SECTION("Set left of BinaryNode")
    {
        BinaryNode left_node(2);
        parent.left(left_node);
        REQUIRE(parent.left() == &left_node);
        REQUIRE(left_node.parent() == &parent);
        REQUIRE(left_node.depth() == parent.depth() + 1);
    }

    SECTION("Set right of BinaryNode")
    {
        BinaryNode right_node(2);
        parent.right(right_node);
        REQUIRE(parent.right() == &right_node);
        REQUIRE(right_node.parent() == &parent);
        REQUIRE(right_node.depth() == parent.depth() + 1);
    }

    SECTION("Retrieve left of BinaryNode with no left set")
    {
        REQUIRE(parent.left() == nullptr);
    }

    SECTION("Retrieve right of BinaryNode with no right set ")
    {
        REQUIRE(parent.right() == nullptr);
    }
}

TEST_CASE("BinaryNode relatives checking", "[binary_node][node]")
{

    BinaryNode n(1);
    SECTION("Has child with child contained")
    {
        BinaryNode l(2);
        BinaryNode r(3);
        n.left(l);
        n.right(r);
        REQUIRE(n.has_child(l));
        REQUIRE(n.has_child(r));
    }

    SECTION("Has child with incorrect child contained") 
    {
        BinaryNode l(2);
        BinaryNode r(3);
        BinaryNode dummy(4);
        REQUIRE(!n.has_child(dummy));

        n.left(l);
        n.right(r);
        REQUIRE(!n.has_child(dummy));
    }

    SECTION("Has parent with correct parent") {
        BinaryNode parent(2);
        parent.left(n);
        REQUIRE(n.has_parent(parent));
    }

    SECTION("Has parent with different parent") 
    {
        BinaryNode parent(2);
        BinaryNode dummy(3);
        REQUIRE(!n.has_parent(dummy));
        parent.left(n);
        REQUIRE(!n.has_parent(dummy));
    }

}

TEST_CASE("Parent and Children collection of BinaryNode","[binary_node][node]"){
    
    BinaryNode n(1);
    SECTION("Retriving children with no children set"){
        REQUIRE(n.children().empty());
    }

    SECTION("Retrieving with one child set"){
        BinaryNode l(2);
        n.left(l);
        REQUIRE(n.children().size() == 1);
        REQUIRE(n.children().count(&l) == 1);
    }

    SECTION("Retrieiving with two children set"){
        BinaryNode l(2);
        BinaryNode r(3);
        n.left(l);
        n.right(r);
        REQUIRE(n.children().size() == 2);
        REQUIRE(n.children().count(&l) == 1);
        REQUIRE(n.children().count(&r) == 1);
    }
}
