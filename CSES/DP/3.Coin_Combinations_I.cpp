#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int recur(vector<int> &inp, vector<int> &dp, int n, int i) {
    if(n < 0 || i >= (int)inp.size()) return 1e9;
    if(n == 0) return 0;
 
    if(dp[n] != -1) return dp[n];
 
    int pick = 1 + recur(inp, dp, n - inp[i], i);
 
    int nPick = recur(inp, dp, n, i + 1);
 
    return dp[n] = min(pick, nPick);
}
 
void test_case() {
    int n, targ;
    cin >> n >> targ;
    vector<int> inp(n);
    for(auto &a : inp) cin >> a;
    // sort(inp.rbegin(), inp.rend());
    
    vector<int> dp(targ+1, 0);
 
    // int ans = recur(inp, dp, targ, 0);
 
    // if(ans >= 1e9) cout << -1 << endl;
    // else cout << ans << endl;
    dp[0] = 1;
    int MOD = 1e9 + 7;
 
    for(int i = 1; i <= targ; i++) {
        for(int j = 0; j < n; j++) {
            if(inp[j] <= i) {
                dp[i] = (dp[i] + dp[i - inp[j]]) % MOD;
            }
        }
    }
   cout << dp[targ] << endl;
}
 
 
int main() {
 
    int t = 1;
      // cin >> t;
    while(t--) {
        test_case();
    }
}
