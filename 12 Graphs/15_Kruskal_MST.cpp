#include<iostream>
#include<algorithm>     // For sort function 
using namespace std;

// Writing your own comparator for sorting according to weight 
bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

// Initializing parent & rank data structures
void makeSet(vector<int> &parent, vector<int> &rank, int N) {
    for(int i=0; i<N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Finding parent
int findParent(vector<int> &parent, int node) {
    // Base case
    if(parent[node] == node) {      // Means you've reached the final parent in that Hierarchy (like 4 in case of 7 -> 6 -> 4)
        return node;
    }

    return findParent(parent, parent[node]);
    // For Path Compression, replace above return statement with below return statement
    // return parent[node] = findParent(parent, parent[node]);
}

// Union Set 
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    // Firstly find parents of both 
    u = findParent(parent, u);
    v = findParent(parent, v);

    // Now compare Ranks of parents
    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int MST(vector<vector<int> > &edges, int N, int &connectComp) {
    // Sort the edges on basis of weights
    sort(edges.begin(), edges.end(), cmp);
    // Sorting function time complexity is mlogm, where m is total number of  edges 

    // Initializing parent & rank data structures
    vector<int> parent(N);
    vector<int> rank(N);
    makeSet(parent, rank, N);

    int minWeight = 0;
    connectComp = N;
    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v) {        // When parents are different, merege/union
            minWeight += wt;
            unionSet(u, v, parent, rank);
            connectComp--;
        }
    }

    return minWeight;
}

int main(){
    int N, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int> > edges;

    cout << "Enter details for each edge (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int source, destination, weight;
        cout << "Edge " << i + 1 << ": ";
        cin >> source >> destination >> weight;
        vector<int> temp;
        temp.push_back(source);
        temp.push_back(destination);
        temp.push_back(weight);
        edges.push_back(temp);
    }

    int connectComp;
    int minSpanningTreeWeight = MST(edges, N, connectComp);

    cout << "Minimum Spanning Tree Weight: " << minSpanningTreeWeight << endl;
    cout << "Number of connected components: " << connectComp << endl;

    return 0;
}

/*

Sample Input 1
4
4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1
Minimum Spanning Tree Weight: 9

Sample Input 2
4
4
1 2 6
2 3 2
1 3 2
1 0 2
Sample Output 2
Minimum Spanning Tree Weight: 6

Sample Input 3
6
9
1 2 2
1 4 1
1 5 4
4 5 9
4 3 5
2 4 3
2 3 3
2 6 7
3 6 8
Sample Output 3
Minimum Spanning Tree Weight: 17

*/