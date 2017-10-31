#include <catch.hpp>

#include <directed_acyclic_graph.hpp>
#include <directed_node.hpp>

//zero is connected to 4,6  : one is connected to 2,3,4 etc..
//six is connected to 5
// 0
//      1           
//      |--> 2           
//      |-->      3      
// |--> |-->      |--> 4
//           |--> |-->    5 <--|
// |-->                        6

TEST_CASE("DAG construction","[dag]"){
    
    DirectedNode n0(0);
    DirectedNode n1(1);
    DirectedNode n2(2);
    DirectedNode n3(3);
    DirectedNode n4(4);
    DirectedNode n5(5);
    DirectedNode n6(6);
    n0.add_child(n4); n0.add_child(n6);
    n1.add_child(n2); n1.add_child(n3); n1.add_child(n4);
    n2.add_child(n5);
    n3.add_child(n4); n3.add_child(n5);
    n6.add_child(n5);

    SECTION("Non cyclic construction"){
        DirectedAcyclicGraph dag(n0);
        REQUIRE(dag.nodes().count(&n0) == 1);
        REQUIRE(dag.nodes().count(&n1) == 1);
        REQUIRE(dag.nodes().count(&n2) == 1);
        REQUIRE(dag.nodes().count(&n3) == 1);
        REQUIRE(dag.nodes().count(&n4) == 1);
        REQUIRE(dag.nodes().count(&n5) == 1);
        REQUIRE(dag.nodes().count(&n6) == 1);
    }

    SECTION("Cyclic construction"){
        std::logic_error err("false");
        n5.add_child(n0);
        try{
            DirectedAcyclicGraph dag(n0);
        }catch(const std::logic_error& e){
            err = e;
        }
        REQUIRE(err.what() != "false");
    }
}

TEST_CASE("Lca on Dag" ,"[dag]"){

    DirectedNode n0(0);
    DirectedNode n1(1);
    DirectedNode n2(2);
    DirectedNode n3(3);
    DirectedNode n4(4);
    DirectedNode n5(5);
    DirectedNode n6(6);
    n0.add_child(n4); n0.add_child(n6);
    n1.add_child(n2); n1.add_child(n3); n1.add_child(n4);
    n2.add_child(n5);
    n3.add_child(n4); n3.add_child(n5);
    n6.add_child(n5);
    DirectedAcyclicGraph dag(n0);
    
    SECTION("Two nodes contained in dag"){
        std::unordered_set<DirectedNode*> results = dag.lca(n4, n5);
        REQUIRE(results.count(&n3) == 1);
        REQUIRE(results.count(&n0) == 1);
        REQUIRE(results.size() == 2);
    }
    
    SECTION("Same node"){
        std::unordered_set<DirectedNode*> results = dag.lca(n4, n4);
        REQUIRE(results.count(&n4) == 1);
        REQUIRE(results.size() == 1);
    }

    SECTION("No common ancestor"){
        std::unordered_set<DirectedNode*> results = dag.lca(n0, n1);
        REQUIRE(results.size() == 0);
    }

    SECTION("One node contained in dag"){
        DirectedNode dummy(1);
        std::unordered_set<DirectedNode*> results = dag.lca(n0, dummy);
        REQUIRE(results.size() == 0);
    
    }

    SECTION("Neither node contained in dag"){
        DirectedNode dummy(1);
        DirectedNode dummy2(2);
        std::unordered_set<DirectedNode*> results = dag.lca(dummy2, dummy);
        REQUIRE(results.size() == 0);
    }
}