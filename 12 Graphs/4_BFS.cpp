#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<pair<int, int> > edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // Considering undirected graph
    }
}

void printAdjList(unordered_map<int, list<int> > &adjList) {
    for (auto i : adjList) {
        cout << i.first << " -> ";
        for (auto j : i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }
}

void bfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int sourceNode) {
    queue<int> q;

    q.push(sourceNode);
    visited[sourceNode] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Store front node into ans
        ans.push_back(frontNode);

        // Traverse all neighbours of front node
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int V, vector<pair<int, int> > edges) {
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Printing the adjacency list 
    printAdjList(adjList);

    // Traverse all components of a graph (including case for disconnected graph)
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main() {
    int V, E;
    vector<pair<int, int> > edges;

    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    int i=0;
    while (i<E) {
        int u, v;
        cin >> u >> v;

        edges.push_back(pair<int, int>(u, v));

        i++;
    }

    vector<int> result = BFS(V, edges);

    cout << "BFS traversal: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}


// If you want the answer in sorted form, use set instead of list in unordered_map & replace push_back function with insert 