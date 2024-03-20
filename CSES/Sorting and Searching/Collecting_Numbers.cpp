#include <bits/stdc++.h>
using namespace std;
 
 
#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
 

void test_case() {
  int n;
  cin >> n;

  vector<pair<int, int>> inp;

  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    inp.push_back({x, i});
  }

  sort(begin(inp), end(inp));

  int i = 1;
  int ans = 1;
  while(i < n) {
    if(inp[i].second < inp[i-1].second) ans++;
    i++;
  }
  cout << ans << endl;
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
