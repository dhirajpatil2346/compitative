/*
10 9
1 2
1 3
1 4
3 5
4 6
4 7
7 8
7 9
7 10
*/


#include<bits/stdc++.h>
using namespace std;

#define N 50
bool vis[N]= {false};
queue<int> q;
vector<int> v[N];
void bfs(int source)
{
    q.push(source);
    vis[source]=true;
    while(!q.empty())
    {
        int curr=q.front();
        for(auto child:v[curr])
        {
            if(!vis[child])
            {
                q.push(child);
            }
        }
        vis[curr]=true;
        cout<<curr<<" ";
        q.pop();
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < k; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    /*
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; ++j)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    bfs(1);
}