#include <bits/stdc++.h>
using namespace std;


#define endl "\n" 
#define int long long int
 
vector<int> adj[500005];
int p;


bool isCycle(vector<int> &vis, int u) {
  vis[u] = 2;
  for(auto v : adj[u]) {
    if(vis[v] == 0) {
      if(isCycle(vis, v)) return true;
    } else if(vis[v] == 2) {
      p = v;
      return true;
    }
  }
  vis[u] = 1;
  return false;
}


bool dfs(int u, vector<int> &path, vector<int> &vis) {
  vis[u] = 2;

  path.push_back(u);

  for(auto v : adj[u]) {
    if(vis[v] == 0) {
      if(dfs(v, path, vis)) return true;
    } else if(vis[v] == 2) {
      path.push_back(v);
      return true;
    }
  }
  vis[u] = 1;
  path.pop_back();
  return false;
}

void test_case() {
    int n, m;
    cin >> n >> m;
    set<int> st;

    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      st.insert(a);
    }
    vector<int> vis(n+1, 0);
    for(auto it : st) {
      if(vis[it] == 0) {
        vector<int> path;
        if(isCycle(vis, it)) {
          // cout << p;
          vis.clear();
          vis.resize(n+1, 0);
          dfs(p, path, vis);

          cout << path.size() << endl;
          for(auto a : path) cout << a << " ";
          return;
        }
      }
    }

    cout << "IMPOSSIBLE" << endl;

}
 
signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}