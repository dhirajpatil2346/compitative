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

multiset<int> ms;
int f(int &x)
{
    // I want current be such that it gives me max
    // for (auto &val : ms)
    //     cout << val << " ";
    // cout << endl;
    int current = 0;
    for (int i = 30; i >= 0; i--)
    {
        int asset = (1 << i) - 1;
        if (x & (1 << i))
        {
            // x has this bit
            // so try to skip if possible
            bool possible = true;
            auto it = ms.lower_bound(current);
            // cout << i << " "
                //  << " - *it - " << *it << " " << *it - current << " " << asset << endl;
            if (it == ms.end() || (*it - current) > asset)
            {
                // cout << "fault " << i << endl;
                possible = false;
            }
            if (!possible)
            {
                // cout << i << endl;
                current |= (1 << i);
            }
        }
        else
        {
            // doesn't have this bit
            // try to get this bit
            int new_current = current + (1 << i);
            int limit = new_current + asset;
            auto it = ms.lower_bound(new_current);
            bool possible = true;
            // cout << new_current << endl;
            if (it == ms.end())
                possible = false;
            else if (*it > limit)
                possible = false;
            if (!(*it & (1 << i)))
                possible = false;
            if (possible)
                current = new_current;
        }
        // cout << i << " : current :  " << current << endl;
    }
    // cout << current << endl;
    return x ^ current;
}
void solve()
{
    char query;
    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> query;
        cin >> x;
        if (query == '-')
            ms.erase(ms.find(x));
        else if (query == '+')
            ms.insert(x);
        else
            cout << f(x) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ms.insert(0);
    solve();
    return 0;
}