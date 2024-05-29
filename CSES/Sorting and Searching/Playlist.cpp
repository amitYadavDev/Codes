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
  int n;
  cin >> n;
  vector<int> playList(n);

  for(auto &song : playList) cin >> song;
  int LongestSeqUniqSongs = 1;

  int left = 0 , right = 1;
  map<int, int> unique;
  unique[playList[left]]++;
  while(right < n) {

    unique[playList[right]]++;

    while(unique[playList[right]] == 2) {
      unique[playList[left++]]--;
    }
    LongestSeqUniqSongs = max(LongestSeqUniqSongs, right - left + 1);
    
    right++;
  }

  cout << LongestSeqUniqSongs << endl;
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
