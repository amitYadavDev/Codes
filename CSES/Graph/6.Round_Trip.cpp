#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 

int sv, ev;
bool dfs(int u, vector<int> &ans, vector<bool> &vis, vector<vector<int>> &adj, int p) {
    
    vis[u] = true;
    ans[u] = p;
    // cout << u << " ";

    for(auto v : adj[u]) {
        // if(v == p) continue;
        if(!vis[v]) {
            if(dfs(v, ans, vis, adj, u)) return true;
        } else if(v != p) {
            sv = v;
            ev = u;
            return true;
        }
    }

    return false;
}
 
void test_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    set<int> st;
 
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        st.insert(x);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n+1, false);

    for(auto it : st) {
        
        vector<int> ans(n+1, 0);
        // if(vis[i]) continue;
        // cout << i << endl;

        if(!vis[it] && dfs(it, ans, vis, adj, -1)) {
            vector<int> res;
            int tv = ev;
            res.push_back(ev);
            while(tv != sv) {
                res.push_back(ans[tv]);
                tv = ans[tv];
            }
            res.push_back(ev);

            // if(res.size())

            cout << (int) res.size() << endl;

            for(auto a : res) cout << a << " ";
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;    
}
 
int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}
