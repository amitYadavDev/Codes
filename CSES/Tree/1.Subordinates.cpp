#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int dfs(vector<int> &ans, vector<int> adj[], int &sub, int u) {
    if(ans[u] != -1) return ans[u];
    int temp = 0;
    for(auto v : adj[u]) {
        temp += 1 + dfs(ans, adj, sub, v);
    }
    return temp;
}
 
void test_case() {
    int n;
    cin >> n;
    int node = 2;
 
    vector<int> adj[n+1];
    // cout << " ok\n";
 
    for(int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        adj[x].push_back(node);
        node++;
    }
    
// cout << " ok\n";
    vector<int> ans(n + 1, -1);
 
    for(int i = n; i > 0; i--) {
        int sub = dfs(ans, adj, sub, i);
         ans[i] = sub;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
    
}
