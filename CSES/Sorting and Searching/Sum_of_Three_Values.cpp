#include <bits/stdc++.h>
using namespace std;


#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7



void test_case() {
  int n, t;
  cin >> n >> t;

  vector<int> inp(n);

  for(auto &a : inp) cin >> a;

  map<int, int> um;

  for(int i = 0; i < n; i++) {
    int val = t - inp[i];
    for(int j = i + 1; j < n; j++) {
      if(um.find(val - inp[j]) != um.end()) {
        cout << i+1 << " " << j+1 << " " << um[val-inp[j]];
        return;
      }
    }
    um[inp[i]] = i + 1;
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















