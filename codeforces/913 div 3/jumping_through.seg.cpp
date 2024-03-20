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
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    int l = 0, r = 1e9, k = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        pair<int, int> curr = {0, 0};
        bool fault = false;
        for (auto &val : vp)
        {
            curr.first -= mid, curr.second += mid;
            // this is my segment
            // i want to check if it falls in val

            if (curr.second < val.first || curr.first > val.second)
            {
                fault = true;
                break;
            }
            // 1 3
            if (mid == 7)
            {
                // cout << mid << " " << curr.first << " " << curr.second << endl;
                // cout << " " << val.first << " " << val.second << endl;
            }
            curr.first = max(curr.first, val.first);
            curr.second = min(curr.second, val.second);
            if (mid == 7)
            {
                // cout << mid << " " << curr.first << " " << curr.second << endl;
                // 1 17
                // 0 1
            }
        }
        if (fault)
        {
            l = mid + 1;
        }
        else
        {
            k = mid;
            r = mid - 1;
        }
    }
    cout << k << endl;
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