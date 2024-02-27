#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define inf 10000000000000000LL
vector<int> dijkstra(int n, int i, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, i});


    vector<int> dis(n+1, inf), vis(n+1, 0);
    dis[i] = 0;

    while(!pq.empty()) {
      auto t = pq.top();
      int node = t.second, w = t.first;
      pq.pop();
      if(vis[node]) continue;
      vis[node] = 1;

      for(auto v : adj[node]) {
        if(dis[v.first] > dis[node] + v.second) {
          dis[v.first] = dis[node] + v.second;
          pq.push({dis[v.first], v.first});
        }
      }
    }
    return dis;  
}
void test_case() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj1[n+1], adj2[n+1];
    vector<tuple<int, int, int>> tp;

    for(int i = 0; i < m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      adj1[x].push_back({y, w});
      adj2[y].push_back({x, w});
      tp.push_back({x, y, w});
    } 

    vector<int> dis1 = dijkstra(n, 1, adj1);
    vector<int> dis2 = dijkstra(n, n, adj2);
    int ans = inf;

    for(auto e : tp) {
      int a = get<0>(e), b = get<1>(e), w = get<2>(e);
      ans = min(ans, dis1[a] + dis2[b] + w/2);
    }
    cout << ans << endl;
}
 
signed main(){  
    int t = 1;
    // cin >> t;
    while(t--) test_case();
    return 0;
}
