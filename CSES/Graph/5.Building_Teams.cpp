#include <bits/stdc++.h>
using namespace std;
 
bool bfs(vector<int> adj[], vector<int> &color,
    int src) {
    color[src] = 1;
    queue<int> q;
    q.push(src);
 
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            } else if(color[it] == color[node]) {
                return true;
            }
        }
    }
    return false;
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
    vector<int> color(n+1, -1);
 
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(bfs(adj, color, i)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
 
    for(int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
 
}
 
int main() {
    int t = 1;
     // cin >> t;
    while(t--) {
        test_case();
    }
}