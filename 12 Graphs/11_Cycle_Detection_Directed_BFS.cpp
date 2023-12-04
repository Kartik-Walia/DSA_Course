// ======================================= This code is valid when node start from 1 =======================================
// ======================================= CYCLE DETECION IN DIRECTED GRAPH VIA BFS =======================================
#include<iostream>
#include<list>
#include<queue>
using namespace std;

bool cycleDetection(int N, vector<pair<int, int> > &edges) {
    // preparing adjacency list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // Find all indegree 
    vector<int> indegree(N);
    for(auto i:adj) {
        for(auto j:i.second) {
            indegree[j]++;
        }
    }

    // Push node havign indegree 0 in queue
    queue<int> q;
    // If node starts from 0, then replace for function with for(int i=0; i<N; i++)
    for(int i=1; i<=N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // Do modified BFS 
    int count=0;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        // Increment count
        count++;

        // Update indegree of neighbour
        for(auto neighbour: adj[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    
    if(count == N) {        // Valid Topological Sort (DAG) => Cyclic isn't present
        return false;   
    } else {        // Invalid Topological Sort (Not DAG) => Cyclic is present
        return true;
    }
}

int main(){
    int N, E;

    cout << "Enter the number of vertices: ";
    cin >> N;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<pair<int, int> > edges;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    // Check for cycle
    bool hasCycle = cycleDetection(N, edges);

    if(hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain any cycle." << endl;
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
The graph contains a cycle.


Sample Input 2
5
4
1 2
2 3
3 4
4 5
Sample Output 2
The graph does not contain any cycle.


Sample Input 3
2
1
1 2
Sample Output 3
The graph does not contain any cycle.

*/