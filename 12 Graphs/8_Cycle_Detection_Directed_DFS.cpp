// ======================================= CYCLE DETECION IN DIRECTED GRAPH VIA DFS =======================================
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

bool checkCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, int src) {
    visited[src] = true;
    dfsVisited[src] = true;

    for (auto neighbour : adj[src]) {
        if (!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(adj, visited, dfsVisited, neighbour);
            if (cycleDetected) {
                return true;
            }
        }
        // Visited neighbours will go in the below block
        else if (dfsVisited[neighbour]) {
            return true;
        }
    }

    dfsVisited[src] = false; // On returning the call, mark the node as False
    return false;
}

bool detectCycleInDirectedGraph(int V, vector<pair<int, int> > &edges) {
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // Preparing adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Call DFS for all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool cycleFound = checkCycleDFS(adj, visited, dfsVisited, i);
            if (cycleFound) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<pair<int, int> > edges;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    bool hasCycle = detectCycleInDirectedGraph(V, edges);

    if (hasCycle) {
        cout << "Cycle detected in the directed graph." << endl;
    } else {
        cout << "No cycle detected in the directed graph." << endl;
    }

    return 0;
}

/*

Sample Input 1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1
Cycle detected in the directed graph.


Sample Input 2
5
4
1 2
2 3
3 4
4 5
Sample Output 2
No cycle detected in the directed graph.


Sample Input 3
2
1 
1 2
Sample Output 3
No cycle detected in the directed graph.

*/