#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
vector<vector<int>> dp(501, vector<int>(501, 1e9));
#define pair pair<int, int>
 
void test_case() {
    int n, m;
    cin >> n >> m;
 
 
    vector<pair> adj[n+1];
 
    for(int i = 0; i < m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
        // adj[y].push_back({x, wt});
    }
 
    priority_queue<pair, vector<pair>, greater<pair>> minpq;
    minpq.push({0, 1});
    vector<int> dis(n+1, 1e18);
    dis[1] = 0;
    vector<int> vis(n+1, 0);
 
    while(!minpq.empty()) {
        auto h = minpq.top();
        // int d = h.first;
        int u = h.second;
        minpq.pop();
        if(vis[u] == 1) continue;
        vis[u] = 1;
 
        for(auto v : adj[u]) {
            int x1 = v.first;
            int w = v.second;
 
            if(dis[x1] > dis[u] + w) {
                dis[x1] = dis[u] + w;
                minpq.push({dis[x1], x1});
            }
        }
    }
 
    // for(auto a : dis) cout << a << " ";
    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
   
}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}