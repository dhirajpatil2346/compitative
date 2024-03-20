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

void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> forw(n), backw(n);
    for (LL i = 0; i < n - 1; i++)
    {
        // want to go from i to i + 1
        // trav cost of i is there
        LL bc = 1e18, fr = 1e18;
        if (i > 0)
            bc = v[i] - v[i - 1];
        if ((i + 1) < n)
            fr = v[i + 1] - v[i];
        if (fr <= bc)
        {
            forw[i] = 1;
        }
        else
            forw[i] = fr;
        if (i > 0)
            forw[i] += forw[i - 1];
    }
    for (int i = n - 1; i > 0; i--)
    {
        // want to go from i to i - 1
        // trav cost of i is there
        LL bc = 1e18, fr = 1e18;
        if (i > 0)
            fr = v[i] - v[i - 1];
        if ((i + 1) < n)
            bc = v[i + 1] - v[i];
        if (fr <= bc)
        {
            backw[i] = 1;
        }
        else
            backw[i] = fr;
        if ((i + 1) < n)
            backw[i] += backw[i + 1];
    }
    // for (auto &val : forw)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : backw)
    //     cout << val << " ";
    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        if (a <= b)
        {
            // go from a to b
            LL z = 0;
            if ((a - 1) >= 0)
                z = forw[a - 1];
            cout << forw[b - 1] - z << endl;
        }
        else
        {
            // go from a to b in back-direction
            // b ... a
            LL z = 0;
            if ((a + 1) < n)
                z = backw[a + 1];
            cout << backw[b + 1] - z << endl;
        }
    }
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