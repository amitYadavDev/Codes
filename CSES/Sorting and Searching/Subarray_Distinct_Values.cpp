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
 
  set<int> diffElements;
  multiset<int> diffElementsAtmostK;
 
  int ans = 1;
  diffElements.insert(inp[0]);
  diffElementsAtmostK.insert(inp[0]);
  int l = 0, i = 0;
 
  while(l < n && i < n-1) {
    if(diffElementsAtmostK.count(inp[i+1]) || diffElements.size() < k) {
      diffElements.insert(inp[++i]);
      diffElementsAtmostK.insert(inp[i]);
      // i++;
      ans += (i - l + 1);
      
    } else {
      auto it = diffElementsAtmostK.find(inp[l++]);
      diffElementsAtmostK.erase(it);
      it = diffElementsAtmostK.find(inp[l-1]);
      if(it == diffElementsAtmostK.end())
        diffElements.erase(inp[l-1]);
      // l++;
    }

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
