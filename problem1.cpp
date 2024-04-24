#include "iostream"
#include "vector"
using namespace std;

int sum(vector<int>& v){
    int s = 0;
    for(int i:v) s += i;
    return s;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adjList{{12, 25}, {12, 13, 15}, {13, 5, 2}, {15, 5, 13}, {5, 5}, {2, 13, 25}};
    cout << sum(adjList[n]);
}