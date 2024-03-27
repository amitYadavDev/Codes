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
  queue<int> q;

  for(int i = 1; i <= n; i++) {
    q.push(i);
  }

  bool skip = true;

  while(!q.empty()) {
    int num = q.front();
    q.pop();

    if(skip) {
      q.push(num);
      skip = false;
    } else {
      cout << num << " ";
      skip = true;
    }
  }
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
