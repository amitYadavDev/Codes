#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[200001];


void bfs(int src, vector<int> &dis) {
    queue<int> q;
    dis[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto u : adj[node]) {
            if(dis[u] == -1) {
                dis[u] = dis[node] + 1;
                q.push(u);
            }
        }
    }
}


void test_case() {
    int n;
    cin >> n;
    vector<int> dis, dis1;

    if(n < 2) {
        cout << 0;
        return;
    }

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dis.resize(n+1, -1);

    bfs(1, dis);

    // for(auto d : dis) cout << d << " ";
    int maxDepth = max_element(dis.begin() + 1, dis.end()) - (dis.begin());

    dis.clear();
    dis.resize(n+1, -1);

    bfs(maxDepth, dis);

    int realMaxDepth = max_element(dis.begin() + 1, dis.end()) - (dis.begin());

    dis1.resize(n+1, -1);
    bfs(realMaxDepth, dis1);

    for(int i = 1; i <= n; i++)
        cout << max(dis[i], dis1[i]) << " ";
}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
    
}



