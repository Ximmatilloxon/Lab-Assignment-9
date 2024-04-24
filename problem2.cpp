#include "iostream"
#include "vector"
using namespace std;

bool f(vector<int>& v, int s){
    for (int i:v){
        if (i == s) return true;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    int node1, node2;
    for (int i = 0; i < m; ++i) {
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> node1 >> node2;
        if(f(adjList[node1], node2)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}