/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "Graph.hpp"
using namespace std;

namespace noa{

    Graph Graph::loadGraph(vector<vector<int>> graph){ //load he graph
        for(unsigned int i=0; i<graph.size(); ++i){ // check that the matrix is squre
            if(graph.size() != graph[i].size()){
                throw std::invalid_argument{"Invalid graph: The graph is not a square matrix"};
            }
        }
        // update all the data
        this->g = graph; 
        this->size=graph.size();
        int count=0;
        unsigned int size1 = static_cast<unsigned int>(this->size);
        // count the edges and update
        for(unsigned int i=0; i<size1; i++){
            for(unsigned int j=0; j<size1; j++){
                if(this->getWeight(i,j) != 0){
                    count++;
                }
            }
        }
        this->edge = count;
        return *this;
    }

    int Graph::getSize(){ // return the size of the graph (amount of vertex)
        return this->size;
    }
    
    int Graph::getWeight(unsigned int x, unsigned int y){ // return the edge weight
        return this->g[x][y];
    }

    int Graph::getEdge(){ // return the amount of edge the graph have
        return this -> edge;
    }

    Graph& Graph::update(){ // this function update the graph data after doing operation on the graph
        unsigned int size1 = static_cast<unsigned int>(this->size);
        int count=0; // count the edges and update the object
        for(unsigned int i=0; i<size1; i++){
            for(unsigned int j=0; j<size1; j++){
                if(this->getWeight(i,j) != 0){
                    count++;
                }
            }
        }
        this->edge = count;
        return *this;
    }

    string Graph::printGraph(Graph g){ // print the graph, print the vertex, the edegs and the nghiebor matrix
        string ans = "";
        ans = ans + "this graph have " + to_string(g.getSize()) + " vertex and " + to_string(g.getEdge()) + " edges\n";
        unsigned int n = static_cast<unsigned int>(g.getSize());
        
        for(unsigned int i=0 ; i< n; i++){
            ans = ans + "| ";
            for(unsigned int j=0; j<n; j++){
                ans = ans + to_string(g.getWeight(i,j));
                ans = ans + " ";
            }
            ans = ans + "| \n";
        }
        ans = ans + "\n";
        cout << ans <<endl;
        return ans;
    }

    Graph Graph::operator+(Graph& g2) const{ // adding one graph to another
        unsigned int size1 = static_cast<unsigned int>(this->size);
        vector<vector<int>> gnew(size1, vector<int>(size1,0)); 
        if(size1 != static_cast<unsigned int>(g2.getSize())){ // make sure the matrixes are the same size
            throw std::length_error{"the Graphs are not in the same size"};
        }
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                gnew[i][j] =  this->g[i][j] + g2.getWeight(i,j);
            }
        }
        Graph ng;
        ng.loadGraph(gnew);
        return ng;
    }

    Graph Graph::operator-(Graph& g2) const{ // minus on graph from the other
        unsigned int size1 = static_cast<unsigned int>(this->size);
        vector<vector<int>> gnew(size1, vector<int>(size1,0)); 
        if(size1 != static_cast<unsigned int>(g2.getSize())){ // make sure the matrixes are the same size
            throw std::length_error{"the Graphs are not in the same size"};
        }
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                gnew[i][j] =  this->g[i][j] - g2.getWeight(i,j);
            }
        }
        Graph ng;
        ng.loadGraph(gnew);
        return ng;
    }
    
    Graph& Graph::operator+=(Graph& g2){ // add agraph to the othr graph in the original on
        if(size != g2.getSize()){ // make sure the matrixes are the same size
            throw std::length_error{"the Graphs are not in the same size"};
        }
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                g[i][j] += g2.getWeight(i,j);
            }
        }
        this->update();
        return *this;
    }
    
    Graph& Graph::operator-=(Graph& g2){ // minus a graph from the original one
        if(size != g2.getSize()){ // make sure the matrixes are the same size
            throw std::length_error{"the Graphs are not in the same size"};
        }
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                g[i][j] -= g2.getWeight(i,j);
            }
        }
        this->update();
        return *this;
    }

    Graph& Graph::operator+(){ // plus unari multiple the graph by 1
        return *this;
    }
    
    Graph& Graph::operator-(){ // minus unari multiple the graph by -1
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                g[i][j] *= (-1);
            }
        }
        this->update();
        return *this;
    }

    Graph Graph::operator*(Graph g2) const{ // multiple two matrix 
        if(size != g2.getSize()){ // make sure the matrixes are the same size
            throw std::length_error{"the Graphs are not in the same size"};
        }
        unsigned int size =static_cast<unsigned int>(g2.getSize());
        vector<vector<int>> gnew(size, vector<int>(size,0));
        int x=0; 
        for(unsigned int i=0; i<size; ++i){
            for(unsigned int j=0; j<size; ++j){
                for(unsigned int n=0; n<size; n++){
                    x += (g[i][n]*g2.getWeight(n,j)); 
                }
                gnew[i][j]= x;
                x=0;
            }
        }
        Graph ng;
        ng.loadGraph(gnew);
        return ng;
    }
        
    Graph& Graph::operator++(){ // add one to all the whgeites in the graph
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                g[i][j]++;
            }
        }
        this->update();
        return *this;
    }

    Graph& Graph::operator--(){ // minus one from all the whgeites in the graph
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                g[i][j]--;
            }
        }
        this->update();
        return *this;
    }

    Graph& Graph::operator/=(int a){ // divide all the weightes in the graph by a
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                if(g[i][j] != 0){
                    g[i][j] /= a;
                }
            }
        }
        this->update();
        return *this;
    }

    Graph& Graph::operator*=(int a){ // multiple all the weightes in the graph by a
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){
            for(unsigned int j=0; j<size1; ++j){
                g[i][j] *= a;
            }
        }
        this->update();
        return *this;
    }

    bool Graph::operator==(Graph g2){ // check that two graph are equels
        if(size != g2.getSize()){ // make sure that the graphs are the same size
            return false;
        }
        bool flag = true;
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for(unsigned int i=0; i<size1; ++i){ // check that theey have the same matrix
            for(unsigned int j=0; j<size1; ++j){
                if(g[i][j] != g2.getWeight(i,j)){
                    flag=false;
                }
            }
        }
        if(flag){ // if they have the same matrix so they equalse
            return true;
        }
        if(!(*this > g2) && !(*this < g2)){ // if not bigger and not smaller so equalse
            return true;
        }
        return false; // not equalse
    }
    
    bool Graph::operator!=(Graph g2){ // check that two graph are not equals
        if(*this == g2){ 
            return false;
        }
        return true;
    }
    
    bool Graph::operator<(Graph g2){ // check if one graph is bigger then the other 
        unsigned int diff = static_cast<unsigned int>(g2.getSize() - this->getSize() +1); 
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for (unsigned int i=0; i< diff; ++i){ // check if one graph contain the other 
            for(unsigned int j=0; j<diff; ++j){
                bool flag = true;
                for(unsigned int x=0; x<size1; ++x){
                    for(unsigned int y=0; y<size1; ++y){
                        if(g2.getWeight(i+x, j+y) != this->getWeight(x,y)){
                            flag = false;
                            break;
                        }
                    }
                    if(flag != true){
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        if(g2.edge > this->edge){ // if not contain so check if one have more edge from the other
            return true;
        }
        if(g2.getSize() > this->getSize()){ // check if have more vertex
            return true;
        }
        return false; // not bigger
    }

    bool Graph::operator<=(Graph g2){ // check if <= by checking if < or ==
        if((*this< g2) || (*this == g2)){
            return true;
        }
        return false;
    }
    
    bool Graph::operator>(Graph g2){ // check if one graph is smaller then the other 
        unsigned int diff = static_cast<unsigned int>(g2.getSize() - this->getSize() +1);
        unsigned int size1 = static_cast<unsigned int>(this->size);
        for (unsigned int i=0; i< diff; ++i){ // check if one graph is bigger then the other
            for(unsigned int j=0; j<diff; ++j){
                bool flag = true;
                for(unsigned int x=0; x<size1; ++x){
                    for(unsigned int y=0; y<size1; ++y){
                        if(this->getWeight(i+x, j+y) != g2.getWeight(x,y)){
                            flag = false;
                            break;
                        }
                    }
                    if(flag != true){
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        if(this->getEdge() > g2.getEdge()){ // if not contain so check if one have less edge from the other
            return true;
        }
        if(this->getSize() > g2.getSize()){ // check if have less vertex
            return true;
        }
        return false; // not smaller
    }

    bool Graph::operator>=(Graph g2){ // check if >= by checking if > or ==
        if((*this > g2) || (*this == g2)){
            return true;
        }
        return false;
    }

    ostream& operator<<(ostream& output, Graph& g1){ //print a string that represent the graph 
        unsigned int n =static_cast<unsigned int>(g1.getSize());
        for(unsigned int i=0; i<n; ++i){
            output <<"[";
            for(unsigned int j=0; j<n-1; ++j){
                output << to_string(g1.getWeight(i,j)) << ",";
            }
            output << to_string(g1.getWeight(i,n-1)) << "]" << endl;
        }
        return output;
    }
}
    



