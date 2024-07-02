#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;


 
#define endl "\n" 
// #define int long long int
// #define int long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;


void test_case() {
  int n, m;
  cin >> n >> m;

  multiset<int>  availTickets;
  vector<int> tickets;

  for(int i = 0;  i < n; i++) {
    int ticketPrice;
    cin >> ticketPrice;
    availTickets.insert(ticketPrice);
  }


  while(m--) {
    int offerPrice;
    cin >> offerPrice;
    auto it = availTickets.upper_bound(offerPrice);

    if(it == availTickets.begin()) tickets.push_back(-1); 
    else {
      --it;
      tickets.push_back(*it);
      availTickets.erase(it);
    }
  } 

  for(auto t : tickets) cout << t << " ";
   
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
