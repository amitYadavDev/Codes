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
  vector<int> inp(n);

  for(auto &a : inp) cin >> a;

  int sum = 0;
  int ans = 0;
  map<int, int> mp;
  mp[0] = 1;

  for(auto a : inp) {
    sum += a;

    ans += mp[sum - x];
    mp[sum]++;
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















