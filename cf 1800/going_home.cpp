#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
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

vector<int> ans(vector<int> v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    if (n == 503)
    {
        cout << v[262 - 1] << " " << v[400 - 1] << " " << v[51 - 1] << " " << v[483] << endl;
        // 79557 397801   1721531 1400001
    }
    int diff = (3e7 / v.size()) + 1;
    map<int, int> m;
    int two = 0;
    for (auto &val : v)
    {
        m[val]++;
        if (m[val] == 2)
            two++;
        if (m[val] == 4)
            return {val, val, val, val};
    }
    if (two >= 2)
    {
        vector<int> p;
        for (auto &val : m)
            if (val.second >= 3)
            {
                p.push_back(val.first);
                p.push_back(val.first);
                if (p.size() == 4)
                    return p;
            }
    }
    if (two == 1)
    {
        int p = 0;
        for (auto &val : m)
            if (val.second == 2)
                p = val.first;
        vector<int> a, b;
        int pos = lower_bound(v.begin(), v.end(), p) - v.begin();
        for (int i = 0; i < pos; i++)
        {
            int diff = p - v[i];
            auto it = lower_bound(v.begin(), v.end(), p + diff) - v.begin();
            if (it == v.size() || v[it] != (p + diff))
                continue;
            return {p + diff, v[i], p, p};
        }
    }
    for (int i = 0; i <= diff; i++)
    {
        int f = -1, b = -1;
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            int ind = lower_bound(v.begin(), v.end(), v[j] + i) - v.begin();
            if (ind <= j)
                ind = j + 1;
            if (ind >= n || v[ind] != (v[j] + i))
                continue;
            else
            {
                // if (i == 0)
                // {
                //     cout << j << " " << ind << endl;
                // }
                s.insert(j);
                s.insert(ind);
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--)
        {
            int ind = lower_bound(v.begin(), v.end(), v[j] + i) - v.begin();
            if (ind <= j)
                ind = j + 1;
            if (ind >= n || v[ind] != (v[j] + i))
                continue;
            else
            {
                // if (i == 0)
                // {
                //     cout << j << " " << ind << endl;
                // }
                s.insert(j);
                s.insert(ind);
                break;
            }
        }
        if (i == 0)
        {
            // cout << s.size() << endl;
        }
        if (s.size() < 4)
            continue;
        vector<int> a;
        for (auto &val : s)
            a.push_back(v[val]);
        return a;
    }
    return {-1};
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> a = ans(v);
    if (a.front() == -1)
    {
        cout << "NO" << endl;
        return;
    }
    sort(a.begin(), a.end());
    swap(a[1], a[3]);
    swap(a[2], a[3]);
    cout << "YES" << endl;
    vector<bool> vis(n);
    for (auto &val : a)
        for (int i = 0; i < n; i++)
            if (!vis[i] && v[i] == val)
            {
                vis[i] = true, cout << i + 1 << " ";
                break;
            }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cout << 25e5 / 503 + 1 << endl;
        cout << 397801 - 79557 << endl;
        // solve();
    }
    return 0;
}