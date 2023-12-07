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
struct x {
	int x;
	int y;
	int count;
	string st;
};
 
void dfs(vector<int> &vis, vector<int> adj[], int u, int &last)
{
	vis[u] = false;
 
	for(auto v : adj[u])
	{
		if(vis[v])
		{
			last = v;
			dfs(vis, adj, v, last);
		}
	}
}
 
void test_case()
{
	int n, m;
	cin >> n >> m;
	vector<int> vis(n+1, true);
	vector<int> adj[n+1];
 
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
   vector<int> ans;
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
		{
			int last;
			dfs(vis, adj, i, last);
			ans.pb(i);
		}
	}
	n = ans.size() - 1;
	cout << n << lc;
 
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " " << ans[i+1] <<lc;
	}
 
 
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