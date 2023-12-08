#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
vector<vector<int>> dp(501, vector<int>(501, 1e9));
 
void test_case() {
    int a, b;
    cin >> a >> b;


    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }

            for(int h = 1; h <= i - 1; h++) {
                dp[i][j] = min(dp[i][j], dp[h][j] + dp[i-h][j] + 1);

            }

            for(int v = 1; v <= j - 1; v++) {
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[i][j-v] + 1);
            } 
        }
    }
    cout << dp[a][b] << endl;

   
}
 
int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
}
