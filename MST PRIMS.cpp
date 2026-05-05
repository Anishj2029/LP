#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define V 5   // number of vertices

// Function to find MST using Prim's Algorithm
void prims(int graph[V][V]) {
    int parent[V];     // store MST
    int key[V];        // minimum weights
    bool mst[V];       // visited

    // Initialize
    for(int i = 0; i < V; i++) {
        key[i] = 1e9;   // infinity
        mst[i] = false;
    }

    key[0] = 0;        // start from node 0
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++) {
        int u = -1;

        // find minimum key
        for(int i = 0; i < V; i++) {
            if(!mst[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mst[u] = true;

        // update neighbors
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // print MST
    cout << "Edge \tWeight\n";
    for(int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph);

    return 0;
}