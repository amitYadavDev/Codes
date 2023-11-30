#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 vector<int> res;
 int MOD = 1e9 + 7;

 

void test_case() {
    int n, x;
    cin >> n >> x;
    vector<int> inp(n), val(n);

    for(auto &a : inp) cin >> a;

    for(auto &a : val) cin >> a;

    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j]; // non pick
            int pick = j - inp[i-1];
            if(pick >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][pick] + val[i-1]);
            }
        }
    }

    cout << dp[n][x] << endl;
    
}
 
int main() {
    int t = 1;
      // cin >> t;
    while(t--) {
        test_case();
    }
}
 
