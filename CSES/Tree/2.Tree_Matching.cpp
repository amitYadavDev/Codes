#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[200007];
vector<int> vis(200007, 0);
int ans = 0;
void dfs(int u, int parent) {

    for(auto v : adj[u]) {
        if(v != parent) {
            dfs(v, u);
            if(!vis[v] && !vis[u]) {
                ans++;
                cout << u << " " << v << endl;
                vis[u] = 1;
                vis[v] = 1;
            }
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    n -= 1;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
    
}


