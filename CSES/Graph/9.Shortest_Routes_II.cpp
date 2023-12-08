#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
vector<vector<int>> dp(501, vector<int>(501, 1e9));
#define pair pair<int, int>
 
void test_case() {
    int n, m, q;
    cin >> n >> m >> q;
// cout << "ff";
 
    vector<vector<int>> adj(505, vector<int>(505, 1e12));
 
    for(int i = 0; i <= n; i++) adj[i][i] = 0;
 
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x -= 1;
        y -= 1;
        // duplicate edge with max weight
        adj[x][y] = min(adj[x][y], w);
        adj[y][x] = min(adj[x][y], w);
    }
 
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                
            }
        }        
    }
 
    while(q--) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        if(a > b) swap(a, b);
 
        if(adj[a][b] < 1e12) cout << adj[a][b] << endl;
        else cout << -1 << endl;
    }
   
}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}