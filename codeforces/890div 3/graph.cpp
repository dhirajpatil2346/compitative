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
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    map<LL, set<pair<LL, LL>>> m1, m2;
    for (int i = 0; i < n; i++)
        m1[a[i]].insert({b[i], i}),
            m2[b[i]].insert({a[i], i});
    set<pair<LL, pair<LL, LL>>> s1, s2;
    for (int i = 0; i < n; i++)
        s1.insert({a[i], {b[i], i}}), s2.insert({b[i], {a[i], i}});
    bool alice = true;
    while (s1.size() && s2.size())
    {
        // a will remove with maximum from b
        // b will remove minimum from a
        if (alice)
        {

            // alice wiil keep his max or destroy appo's max
            auto p1 = *prev(s1.end());
            auto p2 = *prev(s2.end());
            if (p1.first - 1 >= p2.first)
            {
                // will keep his
            }
            else if (p1.first - 1 <= p2.first)
            {
                // will destroy oppo
                p1 = p2;
            }
            else
            {
                if (b[p1.second.second] >= a[p2.second.second])
                    p1 = p2;
            }
            s1.erase({a[p1.second.second], {b[p1.second.second], p1.second.second}});
            s2.erase({b[p1.second.second], {a[p1.second.second], p1.second.second}});
            a[p1.second.second]--, b[p1.second.second] = 0;
        }
        else
        {
            // bob wiil keep his max or destroy appo's max
            auto p1 = *prev(s2.end());
            auto p2 = *prev(s1.end());
            if (p1.first - 1 >= p2.first)
            {
                // will keep his
            }
            else if (p1.first - 1 <= p2.first)
            {
                // will destroy oppo
                p1 = p2;
            }
            else
            {
                if (b[p1.second.second] >= a[p2.second.second])
                    p1 = p2;
            }
            s1.erase({a[p1.second.second], {b[p1.second.second], p1.second.second}});
            s2.erase({b[p1.second.second], {a[p1.second.second], p1.second.second}});
            a[p1.second.second] = 0, b[p1.second.second]--;
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