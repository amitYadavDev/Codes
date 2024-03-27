#include <bits/stdc++.h>
using namespace std;

 
 
#define endl "\n" 
// #define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7



void test_case() {
  int n;
  cin >> n;
  vector<int> inp(n);

  map<int, int> distinct;

  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    distinct[x] = 1;
  }

  int totalDistinctNumber = 0;

  for(auto &a : distinct) {
    if(a.second > 0) totalDistinctNumber++;
  }

  cout << totalDistinctNumber << endl;

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
