// ======================================= This code is valid when node start from 0 =======================================
#include<iostream>
#include<list>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int> > &edges, int V, int E) {
    // preparing adjacency list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Find all indegree 
    vector<int> indegree(V);
    for(auto i:adj) {
        for(auto j:i.second) {
            indegree[j]++;
        }
    }

    // Push node havign indegree 0 in queue
    queue<int> q;
    // If node starts from 1, then replace for function with for(int i=1; i<=V; i++)
    for(int i=0; i<V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // Do modified BFS 
    vector<int> ans;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        // Ans store 
        ans.push_back(frontNode);

        // Update indegree of neighbour
        for(auto neighbour: adj[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){
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
    vector<int> result = topologicalSort(edges, V, E);

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
1 -> 4
2 -> 4
4 -> 3

Sample Input
5
5
0 1
0 2
1 4
2 4
4 3

Sample Output
0 1 2 4 3

*/