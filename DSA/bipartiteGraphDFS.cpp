#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj[N];
int color[N];
 
bool dfs(int node, int col, int color[]) {
    color[node] = col; 
    
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            if(dfs(it, !col, color) == false) return false; 
        }
        else if(color[it] == col) {
            return false; 
        }
    }
    
    return true; 
}

int main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i <= n; i++) color[i] = -1; 

    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            if(dfs(i, 0, color) == false) 
                return cout << "NO\n", 0;
        }
    }

    cout << "YES\n";
}