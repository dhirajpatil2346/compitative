#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

int ret(ordered_set &s, int id)
{
    int l = 0, r = 1e9 + 1, ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (s.order_of_key(m) >= id)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans - 1;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int id = k / 2;
    if (k & 1)
        id++;
    multiset<int> mk, me;
    vector<int> v(n), ans;
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < k; i++)
    {
        mk.insert(v[i]);
        if (mk.size() > id)
        {
            me.insert(*prev(mk.end()));
            mk.erase(prev(mk.end()));
        }
    }
    ans.push_back(*prev(mk.end()));
    for (int j = k, i = 0; j < n; j++, i++)
    {
        if (me.find(v[i]) != me.end())
            me.erase(me.find(v[i]));
        else
        {
            mk.erase(mk.find(v[i]));
            if (me.size())
            {
                mk.insert(*me.begin());
                me.erase(me.begin());
            }
        }
        mk.insert(v[j]);
        if (mk.size() > id)
        {
            me.insert(*prev(mk.end()));
            mk.erase(prev(mk.end()));
        }
        
        ans.push_back(*prev(mk.end()));
    }
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
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