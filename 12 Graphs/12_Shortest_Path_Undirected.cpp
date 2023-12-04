#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

vector<int> shortestPath(vector<pair<int, int> > &edges, int n, int m, int src, int destinationNode){
    // Prepare Adjacency List
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);    // Undirected graph
    }

    // Do BFS (prepare the parent data structure)
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto i:adj[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i]=true;
                parent[i] = frontNode;
            }
        }
    }

    // Prepare the shortest path
    vector<int> ans;
    int count = 0;  // To count no. of edges in shortest path
    int currentNode = destinationNode;
    ans.push_back(destinationNode);

    while(currentNode != src) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
        count++;
    }

    // Reverse the answer
    cout << "No. of edges in shortest path: " << count << endl;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n, m; // Number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int> > edges;

    cout << "Enter the edges (pair of vertices) separated by space:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    int src, destinationNode;
    cout << "Enter the source node: ";
    cin >> src;

    cout << "Enter the destination node: ";
    cin >> destinationNode;

    // Find the shortest path
    vector<int> result = shortestPath(edges, n, m, src, destinationNode);

    // Print the result
    cout << "Shortest Path from " << src << " to " << destinationNode << ": ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    

    return 0;
}

/*

    2 --- 5
   /       \
  1 -- 3 -- 8           Start Node = 1
   \       /            Destination Node = 8
    4 -6- 7             Shortest Path = 1 -> 3 -> 8

Sample Input
8
9
1 2
2 5
5 8
1 3
3 8
1 4
4 6
6 7
7 8
1
8

Sample Output
1 3 8

*/