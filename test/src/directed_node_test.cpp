#include <catch.hpp>
#include <directed_node.hpp>

TEST_CASE("Unit tests for directed node", "[directed_node][node]")
{

    DirectedNode n1(1);

    SECTION("Should return correct id")
    {
        REQUIRE(n1.id() == 1);
    }

    SECTION("Fresh node should return empty children set")
    {
        REQUIRE(n1.children().empty());
    }

    SECTION("Fresh node should return empty parents set")
    {
        REQUIRE(n1.parents().empty());
    }

    SECTION("Should be able to add child")
    {
        DirectedNode n2(2);
        n1.add_child(n2);
        REQUIRE(n1.children().size() == 1);
        REQUIRE(n1.children().count(&n2) == 1);
    }

    SECTION("Should be able to add parent")
    {
        DirectedNode n2(2);
        n1.add_parent(n2);
        REQUIRE(n1.parents().size() == 1);
        REQUIRE(n1.parents().count(&n2) == 1);
    }

    SECTION("Should be able to check if a node has a certain parent")
    {
        DirectedNode n2(10);
        n1.add_parent(n2);
        REQUIRE(n1.has_parent(n2));
    }

    SECTION("Should be able to check if a node has a certain child")
    {
        DirectedNode n2(10);
        n1.add_child(n2);
        REQUIRE(n1.has_child(n2));

    }
}