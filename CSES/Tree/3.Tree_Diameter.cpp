#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[200007]; 
int ans = 0;
int x = 1;

void dfs(int u, int parent, int depth) {

    for(auto v : adj[u]) {
        if(v != parent) {
            dfs(v, u, depth + 1);
        }
    }
    
    if(depth > ans) {
        ans = depth;
        x = u;
    }
}
 
void test_case() {
    int n;
    cin >> n;
    // n -= 1;
    vector<int> inDegree(n+1, 0);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


//  4 can be anything b/w [1, n] eg. dfs(2, 0, 0)
    dfs(1, 0, 0);

    dfs(x, 0, 0);

    cout << ans << endl;

}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
    
}
