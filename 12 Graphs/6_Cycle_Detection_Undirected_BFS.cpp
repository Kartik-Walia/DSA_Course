// ======================================= CYCLE DETECION IN UNDIRECTED GRAPH VIA BFS =======================================
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int src)
{
    unordered_map<int, int> parent;

    parent[src] = -1;   // src node has no parent, taking -1 as NULL data
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adj[frontNode]) {
            if (visited[neighbour] == 1 && neighbour != parent[frontNode]) {    // Cycle present condition
                return true;
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection(int V, int E, vector<vector<int> > &edges) {
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;

    // Preparing Adjacency List
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);    // Undirected graph
    }

    // To handle disconnected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool ans = isCyclicBFS(adj, visited, i);
            if (ans == true) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int> > edges;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
    }

    string result = cycleDetection(V, E, edges);

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