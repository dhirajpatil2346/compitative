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

vector<LL> a((int)1e6), lazy((int)1e6);

void up(int ind, int l, int r, int L, int R, LL val)
{
    if (r < l || l > R || r < L)
        return;
    // update child
    lazy[ind * 2] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    a[ind] += lazy[ind];
    lazy[ind] = 0;
    if (l >= L && r <= R)
    {
        a[ind] += val;
        lazy[ind * 2] += val;
        lazy[ind * 2 + 1] += val;
        return;
    }
    int mid = (l + r) / 2;
    up(ind * 2, l, mid, L, R, val);
    up(ind * 2 + 1, mid + 1, r, L, R, val);
}

LL gt(int ind, int l, int r, int L, int R)
{
    // cout << ind << " " << l << " " << r << endl;
    lazy[ind * 2] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    a[ind] += lazy[ind];
    lazy[ind] = 0;
    if (l == L && r == R)
    {
        return a[ind];
    }
    int mid = (l + r) >> 1;
    if (R <= mid)
        return gt(ind * 2, l, mid, L, R);
    return gt(ind * 2 + 1, mid + 1, r, L, R);
}

void solve()
{
    LL n, q, x, l, r, val;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        up(1, 0, n - 1, i, i, x);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            cin >> l;
            l--;
            // cout << l << endl;
            cout << gt(1, 0, n - 1, l, l) << endl;
        }
        else
        {
            cin >> l >> r >> val;
            l--,r--;
            up(1, 0, n - 1, l, r, val);
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}