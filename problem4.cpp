#include "iostream"
#include "vector"
using namespace std;

void dfs(vector<vector<int>>& adjList, int start, vector<int>& distance){
    static int time = 0;
    time++;
    distance[start] = time;
    for(int vertex:adjList[start]){
        if (distance[vertex] == -1) dfs(adjList, vertex, distance);
    }
}

int str(vector<int>& d){
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] == -1) return i;
    }
    return -1;
}

int main(){
    int n, e, m;
    cin >> n >> e;
    vector<vector<int>> adjList(n);
    int node1, node2;
    for (int i = 0; i < e; ++i) {
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
        m = max(max(node2, node1), m);
    }
    vector<int> d(n, -1);
    int count = 0, start = 0;
    while (start != -1) {
        dfs(adjList, start, d);
        start = str(d);
        count++; // 2
        if (start > m){
            count++;
            break;
        }
    }
    cout << count;
}