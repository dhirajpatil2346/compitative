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
    // a will remove with maximum from b
    // b will remove minimum from a

    // sort b in decr
    // sort a in incr

    LL n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    set<pair<LL, LL>> s1, s2;
    for (int i = 0; i < n; i++)
        s1.insert({a[i], i}), s2.insert({b[i], i});
    bool alice = true;
    while (s1.size() && s2.size())
    {
        // a will remove with maximum from b
        // b will remove minimum from a
        // while (s1.size())
        // {
        //     auto p = *s1.begin();
        //     if (a[p.second] == 0)
        //         s1.erase(s1.begin());
        //     else
        //         break;
        // }
        // while (s2.size())
        // {
        //     auto p = *prev(s2.end());
        //     if (b[p.second] == 0)
        //         s2.erase(prev(s2.end()));
        //     else
        //         break;
        // }
        // if (s1.size() == 0 || s2.size() == 0)
        //     break;
        if (alice)
        {
            // a will keep his max
            auto p = *prev(s1.end());
            // a will erase max of s2
            auto p1 = *prev(s2.end());
            // cout << p.second << " " << p1.second << endl;
            if (p.first - 1 >= p1.first)
            {
            }
            else
            {
                p = p1;
            }
            s1.erase({a[p.second], p.second});
            s2.erase({b[p.second], p.second});
            a[p.second]--;
            b[p.second] = 0;
        }
        else
        {
            // b will keep his max - 1 or a's max he will erase
            auto p = *prev(s2.end());
            auto p1 = *prev(s1.end());
            if (p.first - 1 >= p1.first)
            {
            }
            else
            {
                p = p1;
            }
            s1.erase({a[p.second], p.second});
            s2.erase({b[p.second], p.second});
            a[p.second] = 0;
            b[p.second]--;
        }
        alice = !alice;
        // for (auto &val : a)
        //     cout << val << " ";
        // cout << endl;
        // for (auto &val : b)
        //     cout << val << " ";
        // cout << endl;
        // cout << endl;
    }
    cout << accumulate(a.begin(), a.end(), 0ll) -
                accumulate(b.begin(), b.end(), 0ll)
         << endl;
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