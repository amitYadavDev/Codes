#include <bits/stdc++.h>
using namespace std;
 
 
#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
 

void test_case() {
  int n, k;
  cin >> n >> k;
 
  vector<int> inp(n);
 
  for(auto &a : inp) cin >> a;

  if(k == 1) {
    for(auto a : inp) cout << a << " ";
      return;
  }
 
  multiset<int> st1, st2;

  int left = 0;
  int right = 0;
  int sz = k / 2;
  if(k%2 == 1) sz++;
  // cout << sz << endl;

  while(right < n) {
    st1.insert(inp[right]);
    // auto it;
    if(st1.size() > sz) {
      auto it = st1.end();
      --it;
      st2.insert(*it);
      st1.erase(it);
    }
    if(right >= k - 1) {
      cout << *st1.rbegin() << " ";
      if(st1.find(inp[left]) != st1.end()) {
        st1.erase(st1.find(inp[left]));
        st1.insert(*st2.begin());
        st2.erase(st2.begin());
      } else {
        st2.erase(st2.find(inp[left]));
      }
      left++;
    }
    // for(auto a : st1) cout << a << " ";
    //   cout << endl;
    // for(auto a : st2) cout << a << " f ";
    //   cout << endl;
    right++;
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
