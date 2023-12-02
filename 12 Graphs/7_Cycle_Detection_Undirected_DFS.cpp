// ======================================= CYCLE DETECION IN UNDIRECTED GRAPH VIA DFS =======================================
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj) {
    visited[src] = true;

    for (auto neighbour : adj[src]) {
        if (!visited[neighbour]) {
            bool cycleDetected = isCyclicDFS(neighbour, src, visited, adj);
            if (cycleDetected) {
                return true;
            }
        } else if (neighbour != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int> > &edges, int vertex, int edge) {
    unordered_map<int, list<int> > adj;
    for (int i = 0; i < edge; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // To handle disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if (ans == true) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int vertices, edgesCount;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<vector<int> > edges;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    for (int i = 0; i < edgesCount; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back(vector<int>());
        edges.back().push_back(u);
        edges.back().push_back(v);
    }

    string result = cycleDetection(edges, vertices, edgesCount);

    cout << "Cycle detection result: " << result << endl;

    return 0;
}

/*

Graph considered
  1 -- 2          4 -- 5 -- 6
       |               |    |
       3               7 -- 8 -- 9

Input
9
8
1 2
2 3
4 5
5 6
5 7
6 8
7 8
8 9

Output
Yes

*/