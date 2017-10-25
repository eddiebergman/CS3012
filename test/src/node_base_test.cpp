#include <catch.hpp>

#include <node_base.hpp>

TEST_CASE("Test construction of Node","[node_base][node]"){
        
    SECTION("Node with id constructed with ten should return ten"){
        NodeBase n(10);
        REQUIRE(n.id() == 10);
    }
}