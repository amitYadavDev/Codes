#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 vector<int> res;
 int MOD = 1e9 + 7;
 
 
void test_case() {
   int n, target;
   cin >> n;
 
   vector<int> dp(n+1, 1e7);
   dp[0] = 0;
 
 
   for(int i = 1; i <= n; i++) {
    string s = to_string(i);
    for(auto c : s) {
        int dig = c - '0';
        if(dig != 0) {
            dp[i] = min(dp[i], dp[i - dig] + 1);
        }
    }
   }
   cout << dp[n] << endl;
 
}
 
 
int main() {
 
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}
