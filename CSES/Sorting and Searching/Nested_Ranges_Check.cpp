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

class Fields {
public:
  int first;
  int second;
  int index;
};

bool static comparator(Fields &a, Fields b) {
  if(a.first == b.first) {
    return a.second >= b.second;
  }
  return a.first < b.first;
}


void test_case() {
  int n;
  cin >> n;

  vector<Fields> ranges(n);
  multiset<int> secondElement;

  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    // ranges.push_back({a, b, i});
    ranges[i] = {a, b, i};
    secondElement.insert(b);
  }

  sort(begin(ranges), end(ranges), comparator);
  vector<int> res(n, 0);

  for(auto r : ranges) {
    int second = r.second;
    auto it = secondElement.find(second);
    secondElement.erase(it);

    if(secondElement.size() > 0 && second >= *secondElement.begin()) {
      res[r.index] = 1;
    }
  }

  for(auto &a : res) {
    cout << a << " ";
    a = 0;
  }
  cout << endl;


  secondElement.clear();

  for(auto r : ranges) {
    if(secondElement.size() == 0) {
      secondElement.insert(r.second);
      continue;
    }

    int second = r.second;
    auto it = secondElement.end();
    it--;
    if(second <= *it) {
      res[r.index] = 1;
    }
    secondElement.insert(second);
  }

  for(auto a : res) cout << a << " ";
  cout << endl;
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
