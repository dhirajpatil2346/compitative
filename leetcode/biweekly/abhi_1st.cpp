#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;

vector<LL> prefix_function(string s)
{
    LL n = (LL)s.length();
    vector<LL> pi(n);
    for (LL i = 1; i < n; i++)
    {
        LL j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}

LL mmi(LL a)
{
    return bin(a, mod - 2);
}

const LL sz = 1e7 + 5;
vector<LL> primes;
void sieve()
{
    vector<bool> isp(sz, true);
    isp[0] = false, isp[1] = false;
    for (LL i = 2; i * i <= sz; i++)
        if (isp[i])
            for (LL j = i * i; j < sz; j += i)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}

vector<pair<int, int>> vp = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool correct(int sr, int sc, int n)
{
    if (sr < 0 || sc < 0 || sr >= n || sc >= n)
        return false;
    return true;
}

vector<pair<int, int>> ret(int sr, int sc, int n, vector<vector<bool>> &vis)
{
    vector<pair<int, int>> v;
    for (auto &val : vp)
    {
        if (correct(sr + val.first, sc + val.second, n) && !vis[sr + val.first][sc + val.second])
            v.push_back({sr + val.first, sc + val.second});
    }
    return v;
}

int f(int sr, int sc, vector<vector<int>> &v, vector<vector<bool>> &vis)
{
    if (sr < 0 || sc < 0 || sr >= v.size() || sc >= v[0].size())
        return 1e9;
    vis[sr][sc] = true;
    if (sr == 0 || sc == 0 || sr == v.size() - 1 || sc == v.size() - 1)
        return v[sr][sc];
    int reT = INT_MAX;
    vector<pair<int, int>> curr = ret(sr, sc, (int)v.size(), vis);
    for (auto &val : curr)
    {
        reT = min(reT, f(val.first, val.second, v, vis));
    }
    return max(reT, v[sr][sc]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<vector<bool>> vis1(n, vector<bool>(n, false));
    int lvl = f(n / 2, n / 2, v, vis);
    queue<pair<int, int>> q;
    vis = vis1;
    q.push({n / 2, n / 2});
    vis[n / 2][n / 2] = true;
    vector<vector<char>> ans(n, vector<char>(n, '.'));
    while (!q.empty())
    {
        auto f = q.front();
        ans[f.first][f.second] = 'w';
        q.pop();
        vector<pair<int, int>> curr = ret(f.first, f.second, n, vis);
        for (auto &val : curr)
        {
            cout << val.first << " " << val.second << " " << v[val.first][val.second] << " " << lvl << endl;
            if (v[val.first][val.second] <= lvl)
            {
                cout << val.first << " " << val.second << " " << v[val.first][val.second] << endl;
                vis[val.first][val.second] = true;
                q.push(val);
            }
        }
    }
    for (auto &val : ans)
    {
        for (auto &valu : val)
            cout << valu;
        cout << endl;
    }
    return 0;
}