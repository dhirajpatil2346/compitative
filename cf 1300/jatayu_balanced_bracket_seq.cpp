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

int parent(int sc, vector<int> &par)
{
    if (sc == par[sc])
        return sc;
    return parent(par[sc], par);
}

void solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> par(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
    string s;
    cin >> s;
    stack<int> st;
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            par[i] = 0;
        }
        else if (abs(st.top() - i) > 1)
        {
            par[i] = par[st.top() + 1];
        }
        if (st.empty() || s[i] == '(')
            st.push(i);
        else
        {
            par[i] = parent(st.top(), par);
            st.pop();
        }
    }
    // for (auto &val : par)
    //     cout << val << " ";
    // cout << endl;
    for (auto &val : par)
        ans.insert(val);
    cout << ans.size() << endl;
}
signed main()
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