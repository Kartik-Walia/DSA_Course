#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph {
public:
unordered_map<int, list<int> > adj;

void addEdge(int u, int v, bool direction) {
    // direction = 0 -> Undirected graph 
    // direction = 1 -> Directed graph 

    // Create an edge from u to v 
    adj[u].push_back(v);

    if(direction == 0) {
        adj[v].push_back(u);
    }
}

void printAdjList() {
    for(auto i: adj) {
        cout << i.first << " -> ";
        for(auto j: i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }
}
};


int main(){
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int e;
    cout << "Enter the number of edges" << endl;
    cin >> e;

    graph g;

    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph 
        g.addEdge(u, v, 0);
    }

    // Printing graph 
    g.printAdjList();
    
    return 0;
}

/*

GRAPH
0 --------- 1
|           | \
|           |  2
|           | /
4 --------- 3


INPUT
5
6
0 1
1 2
2 3
3 1
3 4
4 0

OUTPUT
4 -> 3, 0,
3 -> 2, 1, 4,
2 -> 1, 3,
1 -> 0, 2, 3,
0 -> 1, 4,

*/