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
  vector<CustTime> allTimes;
  int l = 0;
  for(int i = 0; i < n; i++) {
    int a, d;
    cin >> a >> d;
    allTimes.push_back({a, 1});
    allTimes.push_back({d, -1});
  }

  sort(begin(allTimes), end(allTimes), comp);

  int maxCustomersAtAtime = 0;
  int curr_max = 0;

  for(auto a : allTimes) {
    curr_max += a.inOrOut;
    maxCustomersAtAtime = max(curr_max, maxCustomersAtAtime);
  }

  cout << maxCustomersAtAtime;

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
