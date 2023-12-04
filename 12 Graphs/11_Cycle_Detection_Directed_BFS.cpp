#include<iostream>
#include<list>
#include<queue>
using namespace std;

int cycleDetection(int N, vector<pair<int, int> > &edges) {
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
    for(int i=0; i<N; i++) {
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
    
    return 0;
}