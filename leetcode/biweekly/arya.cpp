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
    {{-1, 0},
     {1, 0},
     {0, -1},
     {0, 1}}};

void dfs(int sr, int sc, bool allowed, vector<vector<char>> v, string curr, int dir, map<string, int> &m)
{
    if (sr < 0 || sc < 0 || sr >= v.size() || sc >= v[0].size())
        return;
    curr.push_back(v[sr][sc]);
    m[curr]++;
    // cout << sr << " " << sc << " " << curr << endl;
    dfs(sr + vp[dir].first, sc + vp[dir].second, allowed, v, curr, dir, m);
    if (allowed)
    {
        if (dir == 0)
        {
            dfs(sr + vp[1].first, sc + vp[1].second, false, v, curr, abs(1 - dir), m);
        }
        if (dir == 1)
        {
            dfs(sr + vp[0].first, sc + vp[0].second, false, v, curr, abs(1 - dir), m);
        }
        if (dir == 3)
        {
            dfs(sr + vp[2].first, sc + vp[2].second, false, v, curr, 2, m);
        }
        if (dir == 2)
        {
            dfs(sr + vp[3].first, sc + vp[3].second, false, v, curr, 3, m);
        }
    }
}

int Solution(vector<vector<char>> v, vector<string> words)
{
    map<string, int> m;
    int rows = v.size(), cols = v[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int dir = 0; dir < 4; dir++)
                dfs(i, j, true, v, "", dir, m);
        }
    }
    for (auto &val : words)
        cout << val << " " << m[val] << endl;
    int ans = 0;
    for (auto &val : words)
    {
        if (val.size() == 1)
        {
            for (auto &val : v)
                ans += count(val.begin(), val.end(), val[0]);
            cout << ans << endl;
        }
        else
        {
            cout << m[val] << endl;
            ans += m[val];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    cin >> n;
    vector<string> words(n);
    for (auto &val : words)
        cin >> val;
    cout << Solution(v, words) << endl;
    return 0;
}
// 4 3
// a b a c
// x a c d
// y r d s
// 6
// ac cat car bar acdc abaccba
