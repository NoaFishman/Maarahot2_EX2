/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "Algorithms.hpp"
using noa::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    noa::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, -1, 2},
        {1, 0, -2},
        {-4, 0, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout <<"here print"<< endl; // check that theprint functin work
    noa::Graph::printGraph(g1);
    cout << "end print" << endl;

    cout<<g1<< endl; // should print the matrix

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    noa::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    noa::Graph g3 = g1 + g2; // Add the two graphs together.
    cout<<g3<< endl;           // Should print the matrix

    g1 *= -2;        // Multiply the graph by -2.
    cout<<g1<< endl; // Should print the matrix

    g1 /= -2;
    noa::Graph g4 = g1 * g2; // Multiply the two graphs together.
    cout<<g4<< endl;           // Should print the multiplication matrix
    noa::Graph g8 = g1 - g2; // minus g2 from g1
    cout << g8 << endl;

    -g8; // minus unari (multiple the matrix by -1)
    cout << g8 << endl;

    ++g8; // add 1 to all the valus in the matrix
    cout << g8 << endl;

    --g8; // minus 1 to all the valus in the matrix
    cout << g8 << endl;
    
    if (g4 > g1){ // check if g4 > from g1 and print it 
        cout << "g4 > g1" << endl;
    }
    else if (g1 >= g4){ // if g4 ! > from g1 so it <= so make sure and print it
        cout << "g1 >= g4" << endl;
    }

    noa::Graph g7;
    g7.loadGraph(graph);
    if(g1 == g7){ // use the equals sighn on graph
        cout << "g1 == g7" << endl;
    }
    else if (g1 != g7){ // use the unequals sighn on graph
        cout << "g1 != g7" << endl;
    }

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {-1, 0, 2, 0, 0},
        {0, 1, 0,-3, 0},
        {0, 0, 1, 0, 1},
        {-2, 0, 0, 4, 0}};
    noa::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        noa::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }

    return 0;
}
