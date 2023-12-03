// ======================================= CYCLE DETECION IN DIRECTED GRAPH VIA DFS =======================================
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int> > &adj) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected) {
                return true;
            }
        }
        // Visited neighbours will go in the below block
        else if (dfsVisited[neighbour]) {
            return true;
        }
    }

    dfsVisited[node] = false; // On returning the call, mark the node as False
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int> > &edges) {
    // Create adjacency list
    unordered_map<int, list<int> > adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Call DFS for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i <= n; i++) {
        if (!visited[i]) {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cycleFound) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int vertices, edgesCount;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<pair<int, int> > edges;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    for (int i = 0; i < edgesCount; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    bool hasCycle = detectCycleInDirectedGraph(vertices, edges);

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