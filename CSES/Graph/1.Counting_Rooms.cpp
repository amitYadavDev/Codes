#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lc "\n"
#define inf 1e18+1
#define fios ios_base::sync_with_stdio(false)
#define ss cin.tie(NULL)
#define ts to_string
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i <= b; i++) 
// recommendation system using deep learning
void bfs(int i, int j, vector<string> &v, int n, int m)
{
	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, 1, -1, 0};
 
	queue<pair<int, int>> q;
	q.push({i, j});
	v[i][j] = '#';
 
	while(!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
 
		for(int k = 0; k < 4; k++)
		{
			int x1 = i + dx[k];
			int y1 = j + dy[k];
 
			if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && v[x1][y1] == '.')
			{
				q.push({x1, y1});
				v[x1][y1] = '#';
			}
		}
	}
}
void test_case()
{
	int n, m;
	cin >> n >> m;
 
	vector<string> v(n);
 
	for(auto &a : v) cin >> a;
		int ans = 0;
 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(v[i][j] == '.')
			{
				bfs(i, j, v, n, m);
				// for(auto a : v)
				// 	cout << a << lc;
				// cout << lc;
				ans++;
			}
		}
	}
	 cout << ans;
 
}
 
 
 
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
    #endif    
 
 
			ll t = 1;
		//	cin >> t;
 
			while(t--)
			{
				test_case();
			}
}