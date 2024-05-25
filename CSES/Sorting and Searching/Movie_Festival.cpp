// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
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
class MovieTime {
public:
  int startTime;
  int endTime;
};

bool static comp(MovieTime &a, MovieTime &b) {
  return a.endTime < b.endTime;
}

void test_case() {
  int n;
  cin >> n;

  vector<MovieTime> moviesTimes(n);

  for(auto &m : moviesTimes) {
    cin >> m.startTime >> m.endTime;
  }

  sort(begin(moviesTimes), end(moviesTimes), comp);

  int prev = 0, watchedMovies = 0;


  for(auto &m : moviesTimes) {
    if(prev <= m.startTime) {
      prev = m.endTime;
      watchedMovies++;
    }
  }

  cout << watchedMovies;
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
