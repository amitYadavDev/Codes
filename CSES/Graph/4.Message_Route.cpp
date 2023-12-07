#include <bits/stdc++.h>
using namespace std;
struct h {
    int nod;
    int dis;
    vector<int> path;
};
 
void fun(vector<int> &it) {
            cout << it.size() << endl;
            for(auto i : it) cout << i + 1 << " ";
                cout << endl;    
}
void test_case() {
    int n, e;
    cin >> n >> e;
    vector<int> adj[n+1];
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1, 0);
    vector<int> dist(n+1, 1);
    vector<int> parent(n+1, 0);
    queue<int> q;
    // {node, dist}
    q.push(1);
    vis[1] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // vis[node] = 1;
        for(auto v : adj[node]) {
            if(vis[v] == 0) {
                vis[v] = 1;
                parent[v] = node;
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        } 
    }
    if(vis[n] == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    // for(auto a : parent) cout << a << " f";
    //     cout << endl;
 
    vector<int> ans;
    int v = n;
    while(parent[v] != 0) {
        ans.push_back(v);
        v = parent[v];
    }
    ans.push_back(1);
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a << " ";
        cout << endl;
 
}
 
int main() {
    int t = 1;
     // cin >> t;
    while(t--) {
        test_case();
    }
}
