#include <bits/stdc++.h>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define LL long long
#define endl "\n"
const LL modulo = 1e9 + 7;

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
    res = (res * res) % modulo;
    if (p & 1ll)
        res = (res * a) % modulo;
    return res;
}

LL mmi(LL a)
{
    return bin(a, modulo - 2);
}
int mod(int a, int b)
{
    int tmp = a / b;
    return a - (b * tmp);
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

vector<int> a((int)6e5);

void up(int ind, int l, int r, int pos, int val)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        up(ind * 2, l, mid, pos, val);
    else
        up(ind * 2 + 1, mid + 1, r, pos, val);
    a[ind] = a[ind * 2] + a[ind * 2 + 1];
}

int gt(int ind, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
        return a[ind];
    if (r < l || r < L || R < l)
        return 0;
    int mid = (l + r) / 2;
    return gt(ind * 2, l, mid, L, R) +
           gt(ind * 2 + 1, mid + 1, r, L, R);
}

LL bn(int l, int r, int req, int n)
{
    int fixL = l;
    int ans = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int value = gt(1, 1, n, fixL, mid);
        if (value >= req)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

void build(int ind, int l, int r)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind]++;
        return;
    }
    build(ind * 2, l, (l + r) / 2);
    build(ind * 2 + 1, (l + r) / 2 + 1, r);
    a[ind] = a[ind * 2] + a[ind * 2 + 1];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int N = n;
    ordered_set s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    int c = k % n;
    for (int _ = 0; _ < n; _++)
    {
        N--;
        auto it = s.find_by_order(c);
        cout << *it << " ";
        s.erase(it);
        if (N > 0)
            c = (c + k) % N;
    }
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