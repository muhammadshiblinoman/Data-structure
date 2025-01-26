#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    int grid[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int k; cin >> k;

    int cnt = 0;

    for(int i = 0; i < min(n, m)/2; i++) {
        for(int j = i; j < (m-i); j++) {
            cnt++;
            // cout << grid[i][j] << ' ';
            if(cnt == k) {
                cout << grid[i][j] << '\n';
                return 0;
            }
        }

        for(int j = i+1; j < (n-i); j++) {
            cnt++;
            // cout << grid[j][m-i-1] << ' ';
            if(cnt == k) {
                cout << grid[j][m-i-1] << '\n';
                return 0;
            }
        }

        for(int j = (m-i-2); j >= i; j--) {
            cnt++;
            // cout << grid[n-i-1][j] << ' ';
            if(cnt == k) {
                cout << grid[n-i-1][j] << '\n';
                return 0;
            }
        }

        for(int j = i+1; j < (m-i-2); j++) {
            cnt++;
            // cout << grid[m-j-2][i] << ' ';
            if(cnt == k) {
                cout << grid[j][i] << '\n';
                return 0;
            }
        }
        
    }
}