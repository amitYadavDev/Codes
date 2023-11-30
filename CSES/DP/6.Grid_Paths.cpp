#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 vector<int> res;
 int MOD = 1e9 + 7;
 
 
void test_case() {
   int n;
   cin >> n;
   vector<string> inp(n);
 
   for(auto &a : inp) cin >> a;
    int dp[n][n] = {};
 
    if(inp[n-1][n-1] == '*') {
        cout << 0 << endl;
        return;
    }
 
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == j && i == n - 1) {
                dp[i][j] = 1;
            } else if(inp[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                int res1 = i < n - 1 ? dp[i+1][j] : 0;
                int res2 = j < n - 1 ? dp[i][j+1] : 0;
 
                dp[i][j] = (res1 + res2) % MOD;
            }
        }
    }
 
    cout << dp[0][0] << endl;
 
 
}
 
 
int main() {
 
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
