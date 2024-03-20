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
    multiset<int> odd, even;
    for (int i = 1; i <= n; i++)
    {
        LL x;
        cin >> x;
        if (i & 1)
            odd.insert(x);
        else
            even.insert(x);
    }
    bool alice = true, end = false;
    while (true)
    {
        if (alice)
        {
            // she will remove 3
            while (!end && odd.size() && even.size())
            {
                int b1 = *prev(odd.end());
                int b2 = *prev(even.end());
                odd.erase(prev(odd.end()));
                even.erase(prev(even.end()));

                if (b1 / 3 == 0 || b2 / 3 == 0)
                {
                    odd.insert(b1);
                    even.insert(b2);
                    if (odd.size() >= 2)
                    {
                        b1 = *prev(odd.end());
                        odd.erase(prev(odd.end()));
                        b2 = *prev(odd.end());
                        odd.erase(prev(odd.end()));
                        odd.insert(b1 - 1);
                        odd.insert(b2 - 1);
                    }
                    else if (even.size() >= 2)
                    {
                        b1 = *prev(even.end());
                        even.erase(prev(even.end()));
                        b2 = *prev(even.end());
                        even.erase(prev(even.end()));
                        even.insert(b1 - 1);
                        even.insert(b2 - 1);
                    }
                    else
                    {
                        end = true;
                    }
                    break;
                }
                else
                {
                }
            }
        }
        else
        {
        }
        if (!end)
            alice = !alice;
    }

    if (alice)
        cout << "BOB" << endl;
    else
        cout << "ALICE" << endl;
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