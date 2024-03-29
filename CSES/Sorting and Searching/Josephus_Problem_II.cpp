#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// used - policy based data struture(ordered_set)
 
 
#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;



void test_case() {
  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= n; i++) {
    T.insert(i);
  }

  int idx = k;

  while(T.size() > 0) {
    idx %= T.size();
    int val = *T.find_by_order(idx);
    T.erase(val);
    cout << val << " ";
    idx += k;
  }
  cout << endl;
  
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
