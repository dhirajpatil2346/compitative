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
vector<int> seg((int)6e5, 1e9);
vector<int> vec((int)2e5 + 5, 1e9);

void up(int ind, int l, int r, int pos, int value)
{
    if (r < l)
        return;
    if (l == r)
    {
        vec[l] = value;
        seg[ind] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        up(ind * 2, l, mid, pos, value);
    else
        up(ind * 2 + 1, mid + 1, r, pos, value);
    seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
}

int Get(int ind, int l, int r, int L, int R)
{
    if (r < l)
        return 1e9;
    if (r < L || R < l)
        return 1e9;
    if (l >= L && r <= R)
        return seg[ind];
    int mid = (l + r) / 2;
    return min(Get(ind * 2, l, mid, L, R), Get(ind * 2 + 1, mid + 1, r, L, r));
}

vector<int> ans;
int value = 1e9;
void f(int sc, int par, int curr, vector<int> &track, vector<pair<int, int>> v[], vector<bool> &vis, map<int, int> &pos)
{
    vis[sc] = true;
    up(1, 0, (int)vec.size() - 1, (int)track.size(), curr);
    if (pos.find(sc) != pos.end())

    {
        // cycle detected
        // find minimum
        curr = Get(1, 0, (int)vec.size() - 1, pos[sc] + 1, vec.size());
        if (curr < value)
        {
            value = curr;
            ans.clear();
            for (int i = track.size() - 1; i >= 0; i--)
            {
                ans.push_back(track[i]);
                if (ans.back() == sc)
                    break;
            }
        }
        up(1, 0, (int)vec.size() - 1, (int)track.size(), (int)1e9);
        return;
    }
    pos[sc] = track.size();
    track.push_back(sc);
    for (auto &child_pair : v[sc])
    {
        int pt = child_pair.first, wt = child_pair.second;
        if (pt != par)
            f(pt, sc, wt, track, v, vis, pos);
    }
    track.pop_back();
    up(1, 0, (int)vec.size() - 1, (int)track.size(), (int)1e9);
}

void solve()
{
    value = 1e9;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            vector<int> track;
            map<int, int> pos;
            f(i, 0, 1e9 + 1, track, graph, vis, pos);
        }
    cout << value << " " << ans.size() << endl;
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        // cout << "tc #" << i++ << endl;
        solve();
    }
    return 0;
}