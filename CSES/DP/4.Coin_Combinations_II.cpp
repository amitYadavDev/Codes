#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 vector<int> res;
 int MOD = 1e9 + 7;
 
 
void test_case() {
   int n, target;
   cin >> n >> target;
 
   vector<int> inp(n);
 
   for(auto &a : inp) cin >> a;
 
    vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
 
 
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
 
    for(int i = n - 1; i >= 0; i--) {
        for(int sum = 1; sum <= target; sum++) {
            int skip = dp[i+1][sum];
            int pick = 0;
            if(inp[i] <= sum) {
                pick = dp[i][sum - inp[i]];
            }
            dp[i][sum] = (pick + skip) % MOD;
        }
    }
 
    cout << dp[0][target] << endl;
 
 
}
 
 
int main() {
 
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}
