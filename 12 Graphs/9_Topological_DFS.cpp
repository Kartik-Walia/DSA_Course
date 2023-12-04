// ======================================= This code is valid when node start from 0 =======================================
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void topoSort(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, stack<int> &s, int src) {
    visited[src] = true;

    for (auto neighbour : adj[src]) {
        if (!visited[neighbour]) {
            topoSort(adj,visited, s, neighbour);
        }
    }

    // Whenever the call is returned, push into stack
    cout<<src<<" ";
    s.push(src);
}

vector<int> topologicalSort(int V, int E, vector<vector<int> > &edges) {
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;
    stack<int> s;
    vector<int> ans;

    // Preparing adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // Directed Acyclic Graph (DAG)
    }

    // Call DFS topological sort util function for all components
    // If node starts from 1, then replace for function with for(int i=1; i<=V; i++)
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoSort(adj, visited, s, i);
        }
    }

    // Pushing the answer into ans (by taking out from stack)
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
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

    // Perform topological sort
    vector<int> result = topologicalSort(V, E, edges);

    // Print the result
    cout << "Topological Sort Order: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*

Adjacency List
0 -> 1, 2
1 -> 3
2 -> 3
3 -> 4, 5
4 -> 5
5 ->

Sample Input 
6
7
0 1
0 2
1 3
2 3
3 4
3 5
4 5

*/