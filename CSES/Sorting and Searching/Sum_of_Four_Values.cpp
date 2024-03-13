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
  map<int, pair<int, int>> um;

  for(int i = n - 2; i >= 0; i--) {
    int t = x - inp[i];

    for(int j = 0; j < i; j++) {
      if(um.find(t - inp[j]) != um.end()) {
        cout << i + 1 << " " << j + 1 << " " << um[t-inp[j]].first << " " << um[t-inp[j]].second << endl;
        return;
      }
    }

    for(int k = i + 1; k < n; k++) um[inp[i]+inp[k]] = {i+1, k+1};
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















