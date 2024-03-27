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

  

  for(auto &a : inp) {
    cin >> a;
  }

  sort(begin(inp), end(inp));

  int totalCostToMakeEqualFromMed1 = 0, totalCostToMakeEqualFromMed2 = 0;
  int median1 = inp[n/2], median2 = inp[n/2-1];


  for(auto a : inp) {
    totalCostToMakeEqualFromMed1 += abs(median1 - a);
    totalCostToMakeEqualFromMed2 += abs(median2 - a);
  }
  cout << min(totalCostToMakeEqualFromMed1, totalCostToMakeEqualFromMed2) << endl;

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
