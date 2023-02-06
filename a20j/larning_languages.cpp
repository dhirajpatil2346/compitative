#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int sc, vector<bool> &vis, vector<int> languageowner[], vector<int> lang[])
{
    if (vis[sc] == true)
    {
        return;
    }
    vis[sc] = true;
    for (auto child : languageowner[sc])
    {
        for (auto childd : lang[child])
        {
            if (vis[childd])
            {
                continue;
            }
            dfs(childd, vis, languageowner, lang);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> langaugeowner[n];
    vector<int> lang[m + 1];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (x--)
        {
            int y;
            cin >> y;
            langaugeowner[i].push_back(y);
            lang[y].push_back(i);
        }
    }
    int k = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i, vis, langaugeowner, lang);
        k++;
    }
    if (k != n)
    {
        cout << k - 1 << endl;
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (langaugeowner[i].size() == 0)
            {
                cnt++;
            }
        }
        if (cnt == n)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << (n - cnt) + (cnt - 1) << endl;
        }
    }
    return 0;
}
/*
6 6
0 1 3 5
0 1
0 1
2 1 2
2 3 4
2 5 6



*/