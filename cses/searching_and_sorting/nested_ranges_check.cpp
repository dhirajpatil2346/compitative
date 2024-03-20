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
void solve()
{
    int n;
    cin >> n;
    vector<query> v(n);
    vector<int> vec1(n), vec2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].l >> v[i].r;
        v[i].ind = i;
    }
    sort(v.begin(), v.end(), cmp);
    int mini = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mini <= v[i].l)
            vec2[v[i].ind] = true;
        mini = min(mini, v[i].l);
    }
    mini = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (mini >= v[i].l)
            vec1[v[i].ind] = true;
        mini = max(mini, v[i].l);
    }
    for (auto &val : vec1)
        cout << val << " ";
    cout << endl;
    for (auto &val : vec2)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}