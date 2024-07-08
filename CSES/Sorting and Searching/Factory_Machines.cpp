#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define endl "\n" 
#define int long long int
// #define int long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;

class CustTime {
public:
  int arrivalLeavingTime;
  int inOrOut;
};


bool static comp(CustTime &a, CustTime &b) {
  return a.arrivalLeavingTime <= b.arrivalLeavingTime;
}
         
int isAbleToMakeProducts(int totalTime, vector<int> &machineTime) {
  int products = 0;

  for(auto mt: machineTime) {
    products = products + totalTime / mt;
    if(mt > totalTime) break;
  }
  return products;
} 



void test_case() {
  int n, totalProducts;
  cin >> n >> totalProducts;
  vector<int> machineTime(n);

  for(auto &a : machineTime) cin >> a;

  sort(begin(machineTime), end(machineTime));

  int minTime = 1, maxTime = totalProducts * machineTime[0];

  int ans = 0;
  while(minTime <= maxTime) {
    int timeTaken = (minTime + maxTime) / 2;
    int temp = isAbleToMakeProducts(timeTaken, machineTime);
    // cout << temp << endl;

  if(temp >= totalProducts) {
      ans = timeTaken;
      maxTime = timeTaken - 1;
    } else {
      minTime = timeTaken + 1;
    }
  }
  cout << ans;
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
