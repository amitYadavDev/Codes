#include <bits/stdc++.h>
using namespace std;
 
 
#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
 
 
 
void test_case() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> inp;

  // for(auto &a : inp) cin >> a;
  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    inp.push_back({a, i});
  }

  sort(begin(inp), end(inp));

  int left = 0, right = n - 1;

  while(left < right) {
    if(inp[left].first+inp[right].first == x) {
      cout << inp[left].second << " " << inp[right].second << endl;
      return;
    } else if(inp[left].first + inp[right].first > x) right--;
    else left++;
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
