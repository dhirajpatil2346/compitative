#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<char>> &graph,vector<vector<bool>> &vis, int n, int m, int sr, int sc)
{
    if(sr<0 || sr>=n || sc<0 || sc>=m) return 0;
    if(vis[sr][sc]) return 0;
    vis[sr][sc]=true;
    if(graph[sr][sc]=='0') return 0;
    int ret = 1;
    ret += dfs(graph,vis, n,m, sr+1,sc);
    ret += dfs(graph,vis, n,m, sr-1,sc);
    ret += dfs(graph,vis, n,m, sr,sc+1);
    ret += dfs(graph,vis, n,m, sr,sc-1);
    return ret;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<char>> graph(n,vector<char>(m, ' '));
	    vector<vector<bool>> vis(n,vector<bool>(m, false));
	    for(int i = 0 ; i < n ; i++)
	    {
	        for(int j = 0 ; j < m ; j++)
	        {
	            cin>>graph[i][j];
	        }
	    }
	    vector<int> c;
	    for(int i = 0 ; i < n ; i++)
	    {
	        for(int j = 0 ; j < m ; j++)
	        {
	             int k = (dfs(graph,vis,n,m,i,j));
	            // cout<<k<<endl;
                c.push_back(k);
	        }
	    }
	    sort(c.rbegin(), c.rend());
	    int ans=0;
	    for(int i = 1 ; i < c.size() ; i+=2)
	    {
	        ans+=c[i];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
