#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj[N];
int Col[N];

bool check( int node, vector<int>adj[], int Col[] ) {
    queue<int>q;
    q.push(node);
    Col[node] = 0;

    while( !q.empty() ) {
        int n = q.front();
        q.pop();
        
        for( int adjNode: adj[n] ) {
            if( Col[adjNode] == -1 ) {
                q.push(adjNode);
                Col[adjNode] = !Col[n];
            }
            else if( Col[adjNode] == Col[n] ) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        Col[i] = -1;
    }

    while(m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for( int i = 0; i < n; i++ ) {
        if( Col[i] == -1 ) {
            if( check(i, adj, Col ) == false) {
                return cout << "NO Bipartite Graph\n", 0;
            }
        }
    }
    cout << "YES Bipartite Graph\n";

}