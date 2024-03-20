#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
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

struct query
{
    int l, r, ind = 0;
    bool son = false, father = false;
    query()
    {
        l = 0, r = 0;
    }
    query(int a, int b, int c)
    {
        l = a, r = b, ind = c;
    }
};

bool cmp(query &a, query &b)
{
    if (a.r != b.r)
        return a.r < b.r;
    return a.l > b.l;
}
vector<int> a((int)2e6);

void up(int ind, int l, int r, int pos)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind]++;
        return;
    }
    int mid = (l + r) / 2ll;
    if (pos <= mid)
        up(ind * 2, l, mid, pos);
    else
        up(ind * 2 + 1, mid + 1, r, pos);
    a[ind] = a[ind * 2] + a[ind * 2 + 1];
}

int gt(int ind, int l, int r, int L, int R)
{
    if (r < l || r < L || R < l)
        return 0;
    if (l >= L && r <= R)
        return a[ind];
    int mid = (l + r) / 2ll;
    return gt(ind * 2, l, mid, L, R) +
           gt(ind * 2 + 1, mid + 1, r, L, R);
}

void solve()
{
    int n;
    cin >> n;
    vector<query> v(n);
    vector<int> vec1(n), vec2(n);
    vector<int> value;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].l >> v[i].r;
        value.push_back(v[i].l);
        value.push_back(v[i].r);
        v[i].ind = i;
    }
    sort(value.begin(), value.end());
    map<int, int> value_to_pt;
    value_to_pt[value[0]] = 0;
    int counter = 1;
    for (int i = 1; i < 2 * n; i++)
        if (value[i] != value[i - 1])
            value_to_pt[value[i]] = counter++;
    counter--;
    // 0 to counter
    for (auto &val : v)
        val.l = value_to_pt[val.l], val.r = value_to_pt[val.r];
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        // at left your children are there
        // childs are whose left greater than or equals me
        vec1[v[i].ind] = gt(1, 0, counter, v[i].l, counter);
        up(1, 0, counter, v[i].l);
    }
    for (auto &val : a)
        val = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // at right your parents are there
        // parents are who are less than or equals me
        vec2[v[i].ind] = gt(1, 0, counter, 0, v[i].l);
        up(1, 0, counter, v[i].l);
    }
    for (auto &val : vec1)
        cout << val << " ";
    cout << endl;
    for (auto &val : vec2)
        cout << val << " ";
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}