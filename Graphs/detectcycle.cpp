#include <iostream>
#include <list>

using namespace std;

class Graph{
    int V; // vertices
    list<int>* adj; // pointer to the adjecency list
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}