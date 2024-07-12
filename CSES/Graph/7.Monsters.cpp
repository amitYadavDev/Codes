#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define endl "\n" 
// #define int long long int
// #define int long int
vector<pair<int, int>> adj[500005];
#define inf 1e9
#define MOD 1e9+7
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;

struct Me {
  int x1;
  int y1;
  int dist1;
  string p1;
};

void test_case() {
  int n, m;
  cin >> n >> m;

  vector<string> matrix(n);
  cout << "ok";

  for(auto &ma : matrix) cin >> ma;

  vector<vector<int>> monsterRange(n, vector<int>(m, 1e3));

// ((x, y), dist)
  queue<pair<pair<int, int>, int>> monCurrPos;
  queue<Me> myCurrPos;

  int dir[5] = {0, -1, 0, 1, 0};
  vector<char> path({'L', 'U', 'R', 'D'});
  cout << "ok";

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(matrix[i][j] == 'M') {
        monCurrPos.push({{i, j}, 0});
        monsterRange[i][j] = 0;
      }
      else if(matrix[i][j] == 'A') {
        myCurrPos.push({i, j, 0, ""});
      }
    }
  }
  int cnt = 0;
  while(monCurrPos.size() > 0) {
    cnt++;
    cout << cnt << " ";
    int area = monCurrPos.size();
    int x = monCurrPos.front().first.first;
    int y = monCurrPos.front().first.second;
    int capturedDist = monCurrPos.front().second;
    monCurrPos.pop();
    // cout << area << endl;

    for(int j = 0; j < area; j++) {
      for(int i = 0; i < 4; i++) {
        int xx = x + dir[i];
        int yy = y + dir[i+1];

        if(xx < 0 || xx >= n || yy < 0 || yy >= m || matrix[xx][yy] == '#' || matrix[xx][yy] == '*') continue;
        // cout << xx << " " << yy << endl;

        monCurrPos.push({{xx, yy}, capturedDist + 1});
        matrix[xx][yy] = '*';
        monsterRange[xx][yy] = min(capturedDist + 1, monsterRange[xx][yy]);
      }      
    }
  }

  string pathToExit = "krishna";

  while(myCurrPos.size() > 0) {
    int area = myCurrPos.size();
    int x = myCurrPos.front().x1;
    int y = myCurrPos.front().y1;
    int capturedDist = myCurrPos.front().dist1;
    string p2 = myCurrPos.front().p1;
    myCurrPos.pop();

    if(x == 0 || y == m - 1 || y == 0 || x == n - 1) {
      pathToExit = p2;
      break;
    }

    for(int i = 0; i < area; i++) {
      for(int j = 0; j < 4; j++) {
        int xx = x + dir[j];
        int yy = y + dir[j+1];
        string p3 = p2 + path[j];

        if(xx < 0 || xx >= n || y < 0 || y >= m || matrix[xx][yy] == '#' || matrix[xx][yy] == 'o' || monsterRange[xx][yy] <= capturedDist + 1)
          continue;
        matrix[xx][yy] = 'o';
        myCurrPos.push({xx, yy, capturedDist + 1, p3});
      }
    }
  }

    if(pathToExit == "krishna") cout << "NO";
    else {
      cout << "YES" << endl;
      cout << pathToExit.length() << endl;
      cout << pathToExit;
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
