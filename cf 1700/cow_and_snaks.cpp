#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int parent()
{
    return 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sons(n + 1);
    vector<vector<int>> pars(m + 1);
    vector<int> rank(n + 1, 1);
    vector<int> par(n + 1, 0);
    for (int i = 0; i < par.size(); i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        sons[x].push_back(i);
        sons[y].push_back(i);
        pars[i].push_back(x);
        pars[i].push_back(y);
    }
    int ans = 0;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        set<int> colours, consumers;
        stack<int> coloursstack;
        colours.insert(i);
        while (colours.size())
        {
            int sc = *colours.begin();
            vis[sc] = true;
            colours.erase(colours.begin());
            coloursstack.push(sc);
            for (auto &child : sons[sc])
            {
                consumers.insert(child);
                if (!vis[pars[child][0]])
                    colours.insert(pars[child][0]);
                if (!vis[pars[child][1]])
                    colours.insert(pars[child][1]);
            }
        }
        int satneed = consumers.size() + 1;
        int satcapa = coloursstack.size();
        int net = min(0, satcapa - satneed);
        ans += abs(net);
        while (coloursstack.size())
        {
            vis[coloursstack.top()] = true;
            coloursstack.pop();
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}