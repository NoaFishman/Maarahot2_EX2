/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "doctest.h"
#include "Algorithms.hpp"
#include <sstream>


using namespace std;

TEST_CASE("Test graph addition")
{
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    noa::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(noa::Graph::printGraph(g3) == "this graph have 3 vertex and 6 edges\n| 0 2 1 | \n| 2 0 3 | \n| 1 3 0 | \n\n");
}

TEST_CASE("Test graph multiplication")
{
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    noa::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g4) == noa::Graph::printGraph(ge));
}

TEST_CASE("Invalid operations")
{
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 0, 0, 1},
        {1, 2, 0, 0}};
    g2.loadGraph(weightedGraph);
    noa::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    noa::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("TEST GRAPH ADDITION"){
    noa::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 0},
        {1, 0, -1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {-1, 0, 1},
        {0, -1, 0}};
    g2.loadGraph(graph2);
    noa::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g3) == noa::Graph::printGraph(ge));
    CHECK(g3.getEdge() == ge.getEdge());
}

TEST_CASE("test graph minus"){
    noa::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 0},
        {1, 0, 2},
        {0, 0, 0}};
    g1.loadGraph(graph1);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, -1, 0},
        {1, 0, -1},
        {0, 3, 0}};
    g2.loadGraph(graph2);
    noa::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 0},
        {0, 0, 3},
        {0, -3, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g3) == noa::Graph::printGraph(ge));
    CHECK(g3.getEdge() == ge.getEdge());
}

TEST_CASE("test graph +="){
    noa::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 2},
        {1, 0, 2},
        {4, 0, 0}};
    g1.loadGraph(graph1);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, -3},
        {1, 0, -1},
        {0, 3, 0}};
    g2.loadGraph(graph2);
    g1 += g2;
    vector<vector<int>> expectedGraph = {
        {0, 1, -1},
        {2, 0, 1},
        {4, 3, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph -="){
    noa::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph1);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, -3},
        {1, 0, -2},
        {0, 3, 0}};
    g2.loadGraph(graph2);
    g1 -= g2;
    vector<vector<int>> expectedGraph = {
        {0, -3, 5},
        {0, 0, 0},
        {-4, -3, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph + unari"){
    noa::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph1);
    +g1;
    vector<vector<int>> expectedGraph = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph - unari"){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph);
    -g1;
    vector<vector<int>> expectedGraph = {
        {0, 1, -2},
        {-1, 0, 2},
        {4, 0, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph *"){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, -1, 0},
        {1, 0, -1},
        {0, 3, 0}};
    g2.loadGraph(graph2);
    noa::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {-1, 6, 1},
        {0, -7, 0},
        {0, 4, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g3) == noa::Graph::printGraph(ge));
    CHECK(g3.getEdge() == ge.getEdge());
}

TEST_CASE("test graph ++ "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph);
    ++g1;
    vector<vector<int>> expectedGraph = {
        {1, 0, 3},
        {2, 1, -1},
        {-3, 1, 1}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph -- "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph);
    --g1;
    vector<vector<int>> expectedGraph = {
        {-1, -2, 1},
        {0, -1, -3},
        {-5, -1, -1}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph /= "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {3, 0, -3},
        {-4, 0, 0}};
    g1.loadGraph(graph);
    g1 /= 2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 1},
        {1, 0, -1},
        {-2, 0, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
}

TEST_CASE("test graph *= "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {3, 0, -3},
        {-4, -2, 0}};
    g1.loadGraph(graph);
    g1 *= 2;
    vector<vector<int>> expectedGraph = {
        {0, -2, 4},
        {6, 0, -6},
        {-8, -4, 0}};
    noa::Graph ge;
    ge.loadGraph(expectedGraph);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge));
    CHECK(g1.getEdge() == ge.getEdge());
    g1 *= -2;
    vector<vector<int>> expectedGraph2 = {
        {0, 4, -8},
        {-12, 0, 12},
        {16, 8, 0}};
    noa::Graph ge2;
    ge2.loadGraph(expectedGraph2);
    CHECK(noa::Graph::printGraph(g1) == noa::Graph::printGraph(ge2));
    CHECK(g1.getEdge() == ge2.getEdge());
}

TEST_CASE("test graph == "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {3, 0, -3},
        {-4, -2, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 3, -1},
        {2, 0, 4},
        {-1, 5, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 == g2) == true);
    CHECK((g1 == g1) == true);
    CHECK((g1 <= g2) == true);// i added >= and <= 
    CHECK((g1 >= g2) == true);
}

TEST_CASE("test graph == "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {3, 0, -3},
        {-4, -2, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 3, 0},
        {2, 0, 4},
        {0, 5, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 != g2) == true);
    noa::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 3, 0, 4},
        {2, 0, 4, -1},
        {3, -2, 0, -1},
        {0, 5, 1, 0}};
    g3.loadGraph(graph3);
    CHECK((g1 != g3) == true);
}

TEST_CASE("test graph < and > "){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {3, 0, -3},
        {-4, -2, 0}};
    g1.loadGraph(graph);
    noa::Graph g2;
    vector<vector<int>> graph2 = {
        {3, 0, -1, 2},
        {-1, 3, 0, -3},
        {2, -4, -2, 0},
        {0, -1, 3, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 < g2) == true);
    CHECK((g1 <= g2) == true);// i added <=
    CHECK((g2 > g1) == true);
    noa::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 4, 0, 0},
        {0, 0, 2, -3},
        {2, 0, 0, 0},
        {0, -1, 0, 0}};
    g3.loadGraph(graph3);
    CHECK((g1.getEdge() > g3.getEdge()) == true);
    CHECK((g3 < g1) == true);
    CHECK((g2 >= g3) == true);// i added >=
    CHECK((g2 > g3) == true);
    noa::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 4, 0, 0},
        {-3, 0, 2, -3},
        {2, 0, 0, 0},
        {0, -1, 0, 0}};
    g4.loadGraph(graph4);
    CHECK((g1.getEdge() == g4.getEdge()) == true);
    CHECK((g1 < g4) == true);
}

TEST_CASE("test graph <<"){
    noa::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {3, 0, -3},
        {-4, -2, 0}};
    g1.loadGraph(graph);
    std::ostringstream oss;
    oss << g1;
    string output = oss.str();
    CHECK(output == "[0,-1,2]\n[3,0,-3]\n[-4,-2,0]\n");
}

