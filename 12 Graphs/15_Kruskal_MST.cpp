#include<iostream>
using namespace std;

// Initializing parent & rank data structures
void makeSet(vector<int> &parent, vector<int> &rank, int N) {
    for(int i=0; i<N; i++) {
        parent[i] = rank[i];
        rank[1] = 0;
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
void unionSet(int u, int v, vector<int> &parent) {
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

int MST(vector<vector<int> > &edges, int N) {
    vector<int> parent(N);
    vector<int> rank(N);
    makeSet(parent, rank, N);
}

int main(){
    
    return 0;
}