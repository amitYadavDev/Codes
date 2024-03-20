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

  int maxSum = -1e9;
  int sum = 0;

  for(auto &a : inp) {
    sum += a;
    maxSum = max(sum, maxSum);
    if(sum < 0) sum = 0;
    
  }
  cout << maxSum << endl;
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
