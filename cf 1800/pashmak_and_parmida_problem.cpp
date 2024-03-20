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

const LL sz = 4e6 + 5;
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
vector<LL> a(sz);

LL Get(LL ind, LL l, LL r, LL L, LL R)
{
    if (r < l)
        return 0;
    if (r < L || R < l)
        return 0;
    if (l >= L && r <= R)
        return a[ind];
    LL mid = (l + r) / 2ll;
    return Get(ind * 2, l, mid, L, R) + Get(ind * 2 + 1, mid + 1, r, L, R);
}

void update(LL ind, LL l, LL r, LL pos, LL val)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind] += val;
        return;
    }
    LL mid = (l + r) / 2ll;
    if (pos <= mid)
        update(ind * 2ll, l, mid, pos, val);
    else
        update(ind * 2ll + 1ll, mid + 1ll, r, pos, val);
    a[ind] = a[ind * 2] + a[ind * 2ll + 1ll];
}

void build(LL ind, LL l, LL r, vector<LL> &v)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind] = v[l];
        return;
    }
    LL mid = (l + r) / 2ll;
    build(ind * 2ll, l, mid, v);
    build(ind * 2ll + 1ll, mid + 1ll, r, v);
    a[ind] = a[ind * 2] + a[ind * 2 + 1];
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    unordered_map<LL, LL> m;
    vector<LL> freq(n + 1);
    for (auto &val : v)
    {
        m[val]++;
        freq[m[val]]++;
    }
    LL ans = 0;
    build(1ll, 0, n, freq);
    unordered_map<LL, LL> mc;
    for (LL i = 0; i < n; i++)
    {
        LL curr = m[v[i]], val = v[i];
        update(1, 0, n, m[val], -1ll);
        m[v[i]]--;
        mc[v[i]]++;
        ans += Get(1, 0, n, 1, mc[v[i]] - 1ll);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}