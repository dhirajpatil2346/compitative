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

vector<int> a[(int)4e5];
vector<int> third[(int)4e5];

void build(int ind, vector<int> &f, vector<int> &t, int l, int r)
{
    if (r < l)
        return;
    if (r == l)
    {
        if (f[l] != -1)
            a[ind].push_back(f[l]);
        if (t[l] != -1)
            third[ind].push_back(t[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, f, t, l, mid);
    build(ind * 2 + 1, f, t, mid + 1, r);
    for (auto &val : a[ind * 2])
        a[ind].push_back(val);
    for (auto &val : a[ind * 2 + 1])
        a[ind].push_back(val);
    for (auto &val : third[ind * 2])
        third[ind].push_back(val);
    for (auto &val : third[ind * 2 + 1])
        third[ind].push_back(val);
    sort(a[ind].begin(), a[ind].end());
    sort(third[ind].begin(), third[ind].end());
}

int Get(int ind, int l, int r, int &L, int &R)
{
    if (r < L || R < l)
        return 0;
    if (l >= L && r <= R)
        return a[ind].size() - (upper_bound(a[ind].begin(), a[ind].end(), R) - a[ind].begin()) - (third[ind].size() - (upper_bound(third[ind].begin(), third[ind].end(), R) - third[ind].begin()));
    return Get(ind * 2, l, (l + r) / 2, L, R) + Get(ind * 2 + 1, (l + r) / 2 + 1, r, L, R);
}

void solve()
{
    int n, q, x;
    cin >> n >> q;
    vector<map<int, int>> v(n);
    map<int, int> m;
    map<int, int> ind;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
        if (ind.find(x) == ind.end())
            ind[x] = i;
        if (i > 0)
            v[i] = v[i - 1];
        if (m[x] >= x)
            v[i][x] = m[x];
    }
    // 1 kb = 256 int
    // 1 mb = 256 * 1024 int
    // 256 mb = 256 * 256 * 1024
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        map<int, int> curr = v[b];
        map<int, int> left;
        if (a > 0)
            left = v[a - 1];
        for (auto &val : left)
            curr[val.first] -= val.second;
        int ans = 0;
        for (auto &val : curr)
        {
            if (val.second != val.first)
                continue;
            if (left.find(val.first) == left.end() && ind[val.first] <= (a - 1))
                continue;
            ans++;
        }
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t = 1;
    // // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    int z = 1e5 * sqrt(1e5) + 1;
    cout <<( z * 4 )/(1024*1024*256)<< endl;
    
    return 0;
}