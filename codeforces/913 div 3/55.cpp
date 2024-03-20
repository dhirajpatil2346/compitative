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

const LL sz = 1e7 + 1;
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

vector<int> sum(sz);
vector<int> one[56];
vector<int> two[56];
vector<int> three_sum(sz);
vector<int> two_sum(sz);
void sv()
{
    for (int i = 0; i < sz; i++)
    {
        int s = 0;
        int x = i;
        while (x)
        {
            s += (x % 10);
            x /= 10;
        }
        sum[i] = s;
    }

    for (int i = 0; i < sz; i++)
        one[sum[i]].push_back(i);
    // for two
    for (int i = 0; i < sz; i++)
    {
        cout<<i<<" ";
        for (int w = sum[i]; w < 56; w++)
        {
            // left = w - sum[i]
            int left = w - sum[i];
            LL ele = upper_bound(one[left].begin(), one[left].end(), i) - one[left].begin();
            two_sum[i] += ele;
        }
    }
    for (int i = 0; i < sz; i++)
        two[two_sum[i]].push_back(i);
    for (int i = 0; i < sz; i++)
    {
        for (int w = sum[i]; w < 56; w++)
        {
            // left = w - sum[i]
            int left = w - sum[i];
            LL ele = upper_bound(two[left].begin(), two[left].end(), i) - two[left].begin();
            three_sum[i] += ele;
        }
    }
}
void solve()
{
    LL n;
    cin >> n;
    cout << three_sum[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sv();
    // LL t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    return 0;
}