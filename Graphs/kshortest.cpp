/*

Q: Find if there is a path of more than k length from a source

quality: Medium-Hard

Solution: Let the total required be k. Take a path with value k and check the subgraph
for values more than k-w. If that is satisfies the sum is satisfied.
If not take another path if there exist one.

Every backtracking has an entry point and a recursive Util function.

SOURCE: https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/
A shameless copy (of course for practice and understanding).
*/

#include <iostream>
#include <cstring>
#include <list>
#include <vector>

using namespace std;

// define a graph as an adjecency list
// the graph is weighted

class Graph{
    int V; // number of vertices
    // all or some vertices are connected to one another by a weight
    // so we will have 3 entries (source, destination, weight)

    // define adjecency list
    list< pair<int, int>>* adj;

    // define a core private util function
    bool pathMorethanKutil(int src, int k, vector<bool> &path);

public:
    // constructor
    Graph(int V);
    // define member functions
    void addEdge(int u, int v, int w);
    // define a function that can compute the path
    bool pathMorethanK(int src, int k);
};

Graph::Graph(int V){
    this->V = V;

    // initialize the list worth V nodes, singly connected
    adj = new list<pair<int, int>> [V];
}
void Graph::addEdge(int u, int v, int w){
    // add a link between u and v of weight
    adj[u].push_back(make_pair(v,w));

    // Since both the nodes are connected to one another
    adj[v].push_back(make_pair(u, w));
}

bool Graph::pathMorethanKutil(int src, int k, vector<bool> &path){

    // k is the cost, initially equal to the requirement
    if (k<0){
        return true;
    }

    // if k > 0 explore the node from the adjecency matrix
    // recursively check all the paths from the root node
    list< pair<int, int>>::iterator i;
    for (i = adj[src].begin(); i!=adj[src].end(); ++i){
        // expand the source node and check for neighbors and weights
        int v = (*i).first;
        int w = (*i).second;

        // check if it's already in the path
        if (path[v] == true){
            continue;
        }

        if (w>=k){
            return true;
        }

        // the node is now explored
        path[v] = true;
        
        // if the next to the expanded node has the solution
        if(pathMorethanKutil(v, k-w, path)){
            return true;
        }

        // Now backtrack, meaning if this path doesn't lead to the solution
        path[v] = false;
    }
    return false;
}
bool Graph::pathMorethanK(int src, int k){
    // create a path vector or a python list like structure
    vector<bool> path(V, false); // size is number of nodes all initialized to false

    // add source vertex
    path[src] = 1;

    // use util to explore the subarray

}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    g.pathMorethanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    k = 60;
    g.pathMorethanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}