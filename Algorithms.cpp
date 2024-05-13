/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "Algorithms.hpp"

namespace noa{

    // Should print: "1" (true).
    int Algorithms::isConnected(Graph g){

        unsigned int n = static_cast<unsigned int>(g.getSize());
        vector<int> flag(n, 0);

        for(unsigned int x=0; x<n; x++){
            vector<int> dist(n, numeric_limits<int>::max()); // the distance from x to each point
            vector<bool> visited(n, false); //checked if visited
            vector<int> prev(n, -1); // To store previous node in the shortest path
            dist[x] = 0;

            // do it n-1 times (belman ford)
            for (int i = 0; i < n; ++i) {
                for(unsigned int u=0; u<n; ++u){
                    for(unsigned int v=0; v<n; ++v){
                        if(g.getWeight(u,v) != numeric_limits<int>::max() && g.getWeight(u,v) != 0 && dist[u] + g.getWeight(u,v) < dist[v]){
                            dist[v] = dist[u] + g.getWeight(u,v);
                            prev[v] = static_cast<int>(u);
                        }
                    }
                }
            }
            for(unsigned int u=0; u<n; ++u){
                for(unsigned int v=0; v<n; ++v){
                    if(g.getWeight(u,v) != numeric_limits<int>::max() && g.getWeight(u,v) != 0 && dist[u] + g.getWeight(u,v) < dist[v]){
                        dist[v] = numeric_limits<int>::max();
                    }
                }
            }
            bool f =true;
            for(unsigned int i=0; i<n; i++){
                if(dist[i] == numeric_limits<int>::max()){
                    f = false;
                }
            }
            flag[x]=f;
        }

        bool check=true;
        for(unsigned int i=0; i<n; i++){
            if(!flag[i]){
                check=false;
            }
        }

        if(check){
            return 1;
        }
        else{
            return 0;
        }
    }

   
    string Algorithms::shortestPath (Graph g, unsigned int x, unsigned int y){

        int inf = numeric_limits<int>::max();
        unsigned int n =static_cast<unsigned int>(g.getSize());
        vector<int> dist(n, inf); // the distance from x to each point
        vector<int> prev(n, -1); // To store previous node in the shortest path
        dist[x] = 0;
        // do it n -1 times (belman ford)
        for (int i = 0; i < n-1; ++i) {
            for(unsigned int u=0; u<n; ++u){
                for(unsigned int v=0; v<n; ++v){
                    if(g.getWeight(u,v) != 0 && dist[u] + g.getWeight(u,v) < dist[v] && dist[u] != inf){
                        dist[v] = dist[u] + g.getWeight(u,v);
                        prev[v] = static_cast<int>(u);
                    }
                }
            } 
        }

        // the n run to find the cycle
        for(unsigned int u=0; u<n; ++u){
            for(unsigned int v=0; v<n; ++v){
                if(g.getWeight(u,v) != 0 && dist[u] != inf && dist[u] + g.getWeight(u,v) < dist[v]){
                    dist[v] = dist[u] + g.getWeight(u,v);
                    prev[v] = -1;
                }
            }
        }


        // Backtrack to find the shortest path
        unsigned int curr = y;
        string ans = "";
        if(dist[y] == inf){
            ans ="-1";
            return ans;
        }

        for (unsigned int i=0; i<n; ++i){
            if(curr >= n){
                ans ="-1";
                return ans;
            }
            if(curr == x){
                ans = to_string(curr) + ans;
                return ans;
            }
            ans = to_string(curr) + ans;
            ans = "->" + ans;
            curr = static_cast<unsigned int>(prev[curr]);
        }
        return ans;
    }
    
    // Should print: "0" (false).
    string Algorithms::isContainsCycle (Graph g){

        unsigned int n = static_cast<unsigned int>(g.getSize());
        vector<unsigned int> color(n, 0);
        vector<unsigned int> perent(n, numeric_limits<unsigned int>::max());
        int x =0;
        unsigned int curr = numeric_limits<unsigned int>::max();

        for(unsigned int i=0; i<n; ++i){
            if(color[i] == 0){
                x = DFS(g, i,color,perent);
                if( x == 1){
                   for(unsigned int j=0; j<n; ++j){
                        if(color[j] == 3){
                            curr =j;
                        }
                   }
                   break; 
                }
            }
        }
        if(curr == numeric_limits<unsigned int>::max()){
            return "0";
        }
        unsigned int cycle_start = curr;
        string ans = to_string(curr);
        ans = "->" + ans;
        curr = perent[curr];

        if(curr != numeric_limits<unsigned int>::max() ){
            do{
                ans = to_string(curr) + ans;
                ans = "->" + ans;
                curr = perent[curr];
            }
            while(curr != cycle_start && curr != numeric_limits<unsigned int>::max());
            ans = to_string(curr) + ans;
            return "the cycle is: "+ans;
        }
        return "0";

    }

    // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    string Algorithms::isBipartite (Graph g){

        unsigned int n = static_cast<unsigned int>(g.getSize());
        vector<int> color(n, -1);
        color[0] = 0;
        bool flag = false;

        while(!flag){

            // repit n times like in dijkstra and belman ford
            for(unsigned int i=0; i<n; ++i){
                for(unsigned int u=0; u<n; ++u){
                    for(unsigned int v=0; v<n; ++v){
                        if(g.getWeight(u,v) != 0 && color[u] != color[v]){
                            if(color[u] == 0){
                                color[v] = 1;
                            }       
                            else{
                                color[v] = 0;
                            }  
                        }
                        else if(g.getWeight(u,v) != 0 && color[u] == color[v] && color[u] != -1 && u != v){
                            return "0";
                        }
                    }
                } 
            }
            bool f = true;
            for(unsigned int i=0; i<n; ++i){
                if(color[i] == -1){
                    f = false;
                    color[i] = 0;
                    break;
                }
            }
            if( f== true){
                flag = true;
            }


        }
        string A = "";
        string B = "";
        for(unsigned int i = 0; i<n ; ++i){
            if(color[i] == 0){
                A = to_string(i) + "," + A;
            }
            else if(color[i] == 1){
                B = to_string(i) + "," +B;
            }
        }
        string ans = "The graph is bipartite: A={" + A +"}, B={" + B + "}";
        return ans;
    }

    string Algorithms::negativeCycle(Graph g){

        unsigned int n = static_cast<unsigned int>(g.getSize());
        int inf = numeric_limits<int>::max();
        string ans = "";
        unsigned int cycleV = numeric_limits<unsigned int>::max();

        // belman ford for each start vertex
        for(unsigned int s=0; s<n; s++){
            vector<int> dist(n, inf);
            vector<unsigned int> prev(n, numeric_limits<unsigned int>::max());
            dist[s]=0;

            // repit n-1 times
            for(unsigned int i=0; i<n-1; ++i){
                for(unsigned int u=0; u<n; ++u){
                    for(unsigned int v=0; v<n; ++v){
                        if(g.getWeight(u,v) != 0 && dist[u] + g.getWeight(u,v) < dist[v] && prev[u] != v){
                            dist[v] = dist[u] + g.getWeight(u,v);
                            prev[v] = u;
                        }
                    }
                } 
            }

            // the n run to find the cycle
            for(unsigned int u=0; u<n; ++u){
                for(unsigned int v=0; v<n; ++v){
                    if(g.getWeight(u,v) != 0 && dist[u] + g.getWeight(u,v) < dist[v] && prev[u] != v){
                        cycleV = u;
                    }
                }
            }
            if(cycleV == numeric_limits<unsigned int>::max()){
                return "0";
            }

            // finding the cycle
            unsigned int curr = cycleV;
            ans = to_string(curr);
            ans = "->" + ans;
            curr = prev[curr];

            if(cycleV != inf ){
                do{
                    ans = to_string(curr) + ans;
                    ans = "->" + ans;
                    curr = prev[curr];
                }
                while(curr != cycleV);
                ans = to_string(curr) + ans;
                return "the negetive cycle is: "+ans;
            }
        }

        return "0";
    }

    int Algorithms::DFS(Graph g,unsigned int v, vector<unsigned int>& color, vector<unsigned int>& perent){
        color[v] = 1;
        int x = 0;
        for(unsigned int i=0; i<g.getSize(); ++i){
            if(g.getWeight(v,i) != 0 && color[i] == 0){
                perent[i] = v;
                x = DFS(g, i, color, perent);
                if(x==1){
                    return x;
                }
            }
            else if(g.getWeight(v,i) != 0 && color[i] == 1 && i != perent[v]){
                perent[i] = v;
                color[i] = 3;
                return 1;
            }
        }
        color[v] = 2;
        return x;
    }

}