#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define endl "\n" 
// #define int long long int
#define int long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;

multiset<int> elementsInFirstWindow, elementsInSecondWindow;
  int firstHalfSum = 0, secondHalfSum = 0;

void insert(int val, int k) {
  int val1 = *elementsInFirstWindow.rbegin();

// cout << " f ";
  if(val > val1) {
    secondHalfSum += val;
    elementsInSecondWindow.insert(val);
    if(elementsInSecondWindow.size() > k / 2) {
      val = *elementsInSecondWindow.begin();
      secondHalfSum -= val;
      elementsInSecondWindow.erase(elementsInSecondWindow.find(val));

      firstHalfSum += val;
      elementsInFirstWindow.insert(val);
    }
  } else {
      firstHalfSum += val;
      elementsInFirstWindow.insert(val);
       // cout << " fff ";

      if(elementsInFirstWindow.size() > (k + 1) / 2) {
        val = *elementsInFirstWindow.rbegin();
        elementsInFirstWindow.erase(elementsInFirstWindow.find(val));
        firstHalfSum -= val;

        elementsInSecondWindow.insert(val);
        secondHalfSum += val;
      }
    }
}

void erase(int val) {
  if(elementsInFirstWindow.find(val) != elementsInFirstWindow.end()) {
    elementsInFirstWindow.erase(elementsInFirstWindow.find(val));
    firstHalfSum -= val;
  } else {
    elementsInSecondWindow.erase(elementsInSecondWindow.find(val));
    secondHalfSum -= val;
  }

  if(elementsInFirstWindow.empty()) {
    val = *elementsInSecondWindow.begin();
    secondHalfSum -= val;
    elementsInSecondWindow.erase(elementsInSecondWindow.begin());

    firstHalfSum += val;
    elementsInFirstWindow.insert(val);
  }
}

int med(int k) {
  return k % 2 == 1 ? *elementsInFirstWindow.rbegin() : 0;
}

void test_case() {
  int sz, window;
  cin >> sz >> window;

  vector<int> elements(sz);

  for(auto &e : elements) cin >> e;
  elementsInFirstWindow.insert(elements[0]);
  firstHalfSum += elements[0];

  for(int i = 1; i < window; i++) insert(elements[i], window);

  cout << secondHalfSum - firstHalfSum + med(window) << " ";

  // auto it = elementsInFirstWindow.begin();

  // while(it != elementsInFirstWindow.end()) {
  //   cout << *it << " ";
  //   it++;
  // }
  // cout << endl;
  // it = elementsInSecondWindow.begin();

  // while(it != elementsInSecondWindow.end()) {
  //   cout << *it << " ";
  //   it++;
  // }  

  for(int i = window; i < sz; i++) {
     if(window == 1) {
      insert(elements[i], window);
      erase(elements[i - window]);
     } else {
      erase(elements[i - window]);
      insert(elements[i], window);
     }

     cout << secondHalfSum - firstHalfSum + med(window) << " ";
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
