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
struct Dis {
  int dis;
  int a;
  int b;
};

void test_case() {
  int x;
  cin >> x;
  multiset<int> distance({x});
  set<int> trafficLights({0, x});
  int n;
  cin >> n;

  while(n--) {
    int position;
    cin >> position;

    auto it = trafficLights.upper_bound(position);
    auto prev = it;
    prev--;

    distance.erase(distance.find(*it - *prev));
    distance.insert(*it - position);
    distance.insert(position - *prev);
    trafficLights.insert(position);

    auto ans = distance.end();
    ans--;
    cout << *ans << " ";
  }
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
