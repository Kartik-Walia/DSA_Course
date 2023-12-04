#include<iostream>
#include<unordered_map>
#include<list>
#include<limits>    // For INT_MAX
using namespace std;

vector<pair<pair<int, int>, int> > PrimMST(int n, int m, vector<pair<pair<int, int>, int> > &edges) {
    // Create Adjacency List 
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int wt = edges[i].second;

        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }

    vector<int> key(n+1);   // n+1 bcoz we're representing node by index
    vector<bool> mst(n+1); // n+1 bcoz we' representing node by index
    vector<int> parent(n+1);

    // Initialize all 3 data structures
    for(int i=0; i<=n; i++) {
        key[i] = INT_MAX;   // Initializing Key values as Infinity
        parent[i] = -1;
        mst[i] = false;
    }

    // Let's Start the Algorithm
    key[1] = 0;
    parent[1] = -1; // Marking values for source node

    for(int i=1; i<n; i++) {
        int mini = INT_MAX;
        int u;
        // Find the minimum waali node
        for(int v=1; v<=n; v++) {
            if(mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }
        // Mark min node as true 
        mst[u] = true;

        // Check it's adjacent nodes
        for(auto it: adj[u]) {
            int v = it.first;
            int wt = it.second;
            if(mst[v] == false && wt < key[v]) {
                parent[v] = u;
                key[v] = wt;
            }
        }
    }

    vector<pair<pair<int, int>, int> > result;
    // 1st int represents u, 2nd int represents v & 3rd int represents weight 

    for(int i=2; i<=n; i++) {   // 2 se bcoz 1 se chalaya toh glti hojayegi, bcoz 1 ka parent toh -1 hai
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }

    return result;

}

int main(){
    int n, m; // Number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<pair<int, int>, int> > edges;

    cout << "Enter the edges (node1 node2 weight) separated by space:\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back(make_pair(make_pair(u, v), wt));
    }

    // Find the Minimum Spanning Tree (MST)
    vector<pair<pair<int, int>, int> > result = PrimMST(n, m, edges);

    // Print the MST edges
    cout << "Edges of Minimum Spanning Tree (MST):\n";
    for (auto edge : result) {
        cout << "(" << edge.first.first << " - " << edge.first.second << ") Weight: " << edge.second << endl;
    }
    
    return 0;
}

/*

Sample Input 1
5
14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9

Sample Output 1
Edges of Minimum Spanning Tree (MST):
(1 - 2) Weight: 2
(2 - 3) Weight: 3
(1 - 4) Weight: 6
(2 - 5) Weight: 5


Sample Input 2
5
15
1 2 21
1 4 16
2 1 12
2 3 13
2 4 18
2 5 15
3 2 13
3 5 17
4 1 16
4 2 18
4 5 19
5 1 18
5 2 15
5 3 17
5 4 19

Sample Output 2
Edges of Minimum Spanning Tree (MST):
(1 - 2) Weight: 12
(2 - 3) Weight: 13
(1 - 4) Weight: 16
(2 - 5) Weight: 15

*/