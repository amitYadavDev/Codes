#include <bits/stdc++.h>
using namespace std;


#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7



void test_case() {
  int n;
  cin >> n;
  vector<int> inp(n);

  for(auto &a : inp) cin >> a;

  stack<pair<int, int>> st;
  st.push({inp[0], 1});
  vector<int> res;
  res.push_back(0);

  for(int i = 1; i < n; i++) {
    while(!st.empty() && inp[i] <= st.top().first) {
      st.pop();
    }
    if(!st.empty()) res.push_back(st.top().second);
    else res.push_back(0);
    st.push({inp[i], i+1});
  }

  for(auto &a : res) cout << a << " ";
  
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















