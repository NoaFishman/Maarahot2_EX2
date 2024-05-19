/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

namespace noa{

    class Graph{

        vector<vector<int>> g;
        int size;
        int edge;
        
    public:

        Graph loadGraph(vector<vector<int>> g);
        static string printGraph(Graph g);
        int getSize();
        int getWeight(unsigned int x, unsigned int y);
        int getEdge();
        Graph& update();

        // constractor
        Graph(){
            g = {{0}};
            size=0;
        }

        Graph operator+(Graph& g2) const;
        Graph operator-(Graph& g2) const;
        Graph& operator+=(Graph& g2);
        Graph& operator-=(Graph& g2);
        Graph& operator+();// unari
        Graph& operator-();// unari
        
        Graph operator*(Graph g2) const;
        
        Graph& operator++() ;
        Graph& operator--();
        Graph& operator++(int dummy);
        Graph& operator--(int dummy);

        Graph& operator/=(int a);
        Graph& operator*=(int a);

        bool operator==(Graph g2);
        bool operator!=(Graph g2);
        bool operator<(Graph g2);
        bool operator<=(Graph g2);
        bool operator>(Graph g2);
        bool operator>=(Graph g2);
        
        friend std::ostream& operator<<(ostream& output, Graph& g1);
    };
}