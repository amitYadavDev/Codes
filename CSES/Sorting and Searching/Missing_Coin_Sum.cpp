#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define endl "\n" 
#define int long long int
// #define int long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;

class CustTime {
public:
  int arrivalLeavingTime;
  int inOrOut;
};


bool static comp(CustTime &a, CustTime &b) {
  return a.arrivalLeavingTime <= b.arrivalLeavingTime;
}
          



void test_case() {
  int n;
  cin >> n;
  vector<int> coins(n);

  for(auto &c : coins) cin >> c;

  sort(begin(coins), end(coins));

  int minSum = 1;

  for(auto c : coins) {
    if(c > minSum) {
      break;
    }
    minSum += c;
  }

  cout << minSum;
  
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
