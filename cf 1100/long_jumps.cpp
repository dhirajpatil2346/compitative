#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        vector<bool> vis(n+1);
        for (auto i = 1; i < n + 1; i++)
        {
            cin >> v[i];
        }
        // cout<<"end"<<endl;
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            int score = 0;
            int c = i;
            while (c <= n && !vis[c])
            {
                vis[c]=true;
                score += v[c];
                c = c + v[c];
            }
            if(score==0)
            {
                score=v[i];
            }
            ret = max(ret, score);
        }
        cout << ret << endl;
    }
    return 0;
}