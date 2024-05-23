#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;


 
#define endl "\n" 
#define int long long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;

struct roomInfo {
  int arrivalTime;
  int departureTime;
  int rNo;
};

bool static comp(roomInfo &a, roomInfo &b) {
  return a.arrivalTime < b.arrivalTime;
}

void test_case() {
 int n;
  cin >> n;
  vector<roomInfo> vi(n);
  int p = 0;
 
  for(auto &a : vi) {
    cin >> a.arrivalTime >> a.departureTime;
    a.rNo = p++;
  }
 
  sort(begin(vi), end(vi), comp);

  // for(auto &a : vi) {
  //   cout << a.arrivalTime << "  " << a.departureTime << endl;
  // }
 
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
 
  vector<int> roomNo(n);
 
  // minPQ.push(vi[0].second);
  // roomNo.push_back(1);
  int no = 1;
  int maxUsedRooms = 0;
 
  for(int i = 0; i < n; i++) {
    if(!minPQ.empty() && minPQ.top().first < vi[i].arrivalTime)  {
      auto it = minPQ.top();
      minPQ.pop();
      minPQ.push({vi[i].departureTime, it.second});
      roomNo[vi[i].rNo] = it.second;
    } else {
      minPQ.push({vi[i].departureTime, no});
      roomNo[vi[i].rNo] = no++;
    }
    maxUsedRooms = max(maxUsedRooms, roomNo[vi[i].rNo]);
  }
  cout << maxUsedRooms << endl;
  for(auto &r : roomNo) cout << r << " ";
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
