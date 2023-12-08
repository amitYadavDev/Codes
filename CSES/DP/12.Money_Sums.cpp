#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 
void test_case() {
   
   int n;
   cin >> n;
   vector<int> inp(n);
   set<int> st;
   int sum = 0;
   for(auto &a : inp) {
    cin >> a;
    sum += a;
    // st.insert(a);
   }
 
    vector<vector<int>> v;
    v.push_back({});
    st.insert(0);
 
    for(int i = 0; i < n; i++) {
        // int k = v.size();
        set<int> stt = st;
        for(auto it = stt.begin(); it != stt.end(); it++) {
            // vector<int> vp = v[j];
            int p = *it;
            p += inp[i];
            // vp.push_back(inp[i]);
            // v.push_back(vp);
            st.insert(p);
        }
    }
 
    // for(auto a : v) {
    //     int sum1 = 0;
    //     for(auto b : a) {
    //         sum1 += b;
    //     }
    //     if(sum1 > 0 && sum1 <= sum)
    //     st.insert(sum1);
    // }
    st.erase(st.begin());
 
    cout << st.size() << endl;
 
 
    for(auto it = st.begin(); it != st.end(); it++) 
        cout << *it << " ";
 
}
 
 
int main() {
 
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
