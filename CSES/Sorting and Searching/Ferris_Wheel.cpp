#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;


 
#define endl "\n" 
// #define int long long int
// #define int long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;


void test_case() {
  int n, maxWeight;
  cin >> n >> maxWeight;

  vector<int> childWeight(n);

  for(auto &c : childWeight) cin >> c;

  sort(begin(childWeight), end(childWeight));
  
  int left = 0, right = n - 1;
  int requiredGondolas = 0;

  while(left <= right) {

    int w = childWeight[right] + childWeight[left];
    if(w <= maxWeight) left++;
    requiredGondolas++;
    right--;
  }
  // if(left < right) requiredGondolas++;

  cout << requiredGondolas << endl;
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
