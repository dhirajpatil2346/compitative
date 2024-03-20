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
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first >= p2.first;
}

LL sum(LL ind, vector<LL> &a, LL l, LL r, LL L, LL R)
{
    if (r < L)
        return 0;
    if (R < l)
        return 0;
    // cout << l << " " << r << " " << L << " " << R << endl;
    if (l >= L && r <= R)
        return a[ind];
    return sum(ind * 2, a, l, (l + r) / 2, L, R) + sum(ind * 2 + 1, a, (l + r) / 2 + 1, r, L, R);
}

void update(LL ind, vector<LL> &a, LL l, LL r, LL pos)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind]++;
        return;
    }
    LL mid = (l + r) / 2;
    if (pos <= mid)
        update(ind * 2, a, l, mid, pos);
    else
        update(ind * 2 + 1, a, (l + r) / 2 + 1, r, pos);
    a[ind] = a[ind * 2] + a[ind * 2 + 1];
}

void solve()
{
    LL n;
    cin >> n;
    LL ans = 0;
    vector<pair<int, int>> vp(n);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    sort(vp.begin(), vp.end());
    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++)
        s[i] = vp[i].first, e[i] = vp[i].second;
    vector<int> tot;
    for (auto &val : s)
        tot.push_back(val);
    for (auto &val : e)
        tot.push_back(val);
    sort(tot.begin(), tot.end());
    map<int, int> value_to_pt;
    for (int i = 0; i < 2 * n; i++)
        value_to_pt[tot[i]] = i;
    vector<LL> a(8 * n);
    for (int i = n - 1; i >= 0; i--)
    {
        int ep = value_to_pt[e[i]];
        int sp = value_to_pt[s[i]];
        // cout << sp << " " << ep << endl;
        // cout << sp << " " << ep << endl;
        LL x = sum(1, a, 0, 2 * n - 1, (LL)sp, (LL)ep);
        ans += x;
        // cout << s[i] << " " << e[i] << " " << x << endl;
        update(1, a, 0, 2 * n - 1, ep);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
 vector<LL> v(tot.size() + 1);
    for (int i = 0; i < n; i++)
    {
        int sp = value_to_pt[s[i]];
        int ep = value_to_pt[e[i]] + 1;
        v[sp]++, v[ep]--;
    }
    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
    for (auto &val : tot)
        cout << val << " ";
    cout << endl;
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
    for (auto &val : e)
    {
        ans += v[value_to_pt[val]];
    }
    cout << ans - e.size() << endl;


*/