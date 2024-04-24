#include "iostream"
#include "vector"
#include "queue"
using namespace std;

void bfs(vector<vector<int>>& adjList, int start, vector<int>& distance){
    distance[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int vertex: adjList[u]) {
            if(distance[vertex] == -1){
                distance[vertex] = distance[u] + 1;
                q.push(vertex);
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n);
    int node1, node2;
    for (int i = 0; i < e; ++i) {
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    vector<int> d(n, -1);
    bfs(adjList, 0, d);
    for(auto dis:d) cout << dis << " ";
}