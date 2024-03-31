#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;


 
#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;


void test_case() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> vn(n), vm(m);

  for(auto &a : vn) cin >> a;

  for(auto &a : vm) cin >> a;

  sort(begin(vn), end(vn));
  sort(begin(vm), end(vm));
  int i = 0, j = 0;
  int assignedAppartments = 0;

  while(i < n && j < m) {
    int a = vm[j] - k;
    int b = vm[j] + k;
    if(vn[i] >= a && vn[i] <= b) {
      assignedAppartments++;
      i++;
      j++;
    } else if(vn[i] > b) {
      j++;
    } else {
      i++;
    }
  }
  cout << assignedAppartments << endl;
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
