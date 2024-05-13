/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
#include <queue> 
#include <vector>
#include "Graph.hpp"

using namespace std;

namespace noa{

    class Algorithms{

        public:
            
            static int isConnected(Graph g); // Should print: "1" (true).     
            static string shortestPath (Graph g, unsigned int x, unsigned int y); // Should print: 0->1->2.
            static string isContainsCycle (Graph g); // Should print: "0" (false).
            static string isBipartite (Graph g); // Should print: "The graph is bipartite: A={0, 2}, B={1}."
            static string negativeCycle(Graph g);// negative cicle
            static int DFS(Graph g, unsigned int v, vector<unsigned int>& color, vector<unsigned int>& perent);
    };
}