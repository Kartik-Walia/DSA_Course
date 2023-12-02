#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<vector<int> > &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

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

void dfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &component, int sourceNode) {
    // Store in answer 
    component.push_back(sourceNode);
    visited[sourceNode] = true;

    // Har connected node ke liye recursive call 
    for(auto i: adjList[sourceNode]) {
        if(!visited[i]) {
            dfs(adjList, visited, component, i);
        }
    }
}

vector<vector<int> > DFS(int V, int E, vector<vector<int> > &edges) {
    unordered_map<int, list<int> > adjList;
    vector<vector<int> > ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Printing the adjacency list
    printAdjList(adjList);

    // For all nodes call DFS if not visited 
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
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

        // or:
        // std::vector<int> temp;
        // temp.push_back(u);
        // temp.push_back(v);
        // edges.push_back(temp);
    }

    vector<vector<int> > result = DFS(vertices, edgesCount, edges);

    // Result is a vector of vectors where each inner vector represents a connected component in the graph. The total number of connected components in the graph is given by the size of the result vector, which can be obtained using the result.size() function.
    cout << "Number of connected components: " << result.size() << endl;

    cout << "Connected components:\n";
    int componentCount = 0;
    for (const auto &component : result) {
        cout << "Component " << ++componentCount << ": ";
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    // cout << "Number of connected components: " << componentCount << endl;

    return 0;
}


/*

Sample Input 1
5
4
0 2
0 1
1 2
3 4
Sample Output 1
2
0 2 1
3 4


Sample Input 2
9
7
0 1
0 2
0 5
3 6
7 4
4 8
7 8
Sample Output 2
3
0 1 2 5
3 6
4 7 8

*/