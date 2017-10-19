#include <catch.hpp>
#include <node.hpp>
#include <set>

TEST_CASE("Unit tests for node", "[node][unit]")
{

    Node n1(1);

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
        Node n2(2);
        n1.add_child(&n2);
        REQUIRE(n1.children().size() == 1);
        REQUIRE(n1.children().count(&n2) == 1);
    }

    SECTION("Should be able to add parent")
    {
        Node n2(2);
        n1.add_parent(&n2);
        REQUIRE(n1.parents().size() == 1);
        REQUIRE(n1.parents().count(&n2) == 1);
    }

    SECTION("Should be able to add childlren")
    {
        Node n2(2);
        Node n3(3);
        n1.add_children({ &n2, &n3 });
        REQUIRE(n1.children().size() == 2);
        REQUIRE(n1.children().count(&n2) == 1);
        REQUIRE(n1.children().count(&n3) == 1);
        
    }


    SECTION("Should be able to add parents")
    {
        Node n2(2);
        Node n3(3);
        n1.add_parents({ &n2, &n3 });
        REQUIRE(n1.parents().size() == 2);
        REQUIRE(n1.parents().count(&n2) == 1);
        REQUIRE(n1.parents().count(&n3) == 1);
    }
}