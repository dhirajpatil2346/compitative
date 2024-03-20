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

string make(LL n, LL i)
{
    if (n == 0)
        n = 1;
    string s = "";
    while (i)
    {
        if (i & 1)
            s.push_back('1');
        else
            s.push_back('0');
        i /= 2;
    }
    reverse(s.begin(), s.end());
    string s1 = "";
    int diff = n - s.size();
    while (diff--)
        s1.push_back('0');
    s1 += s;
    return s1;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> ans;
    int curr = 0;
    vector<bool> vis(1 << n);
    while (!vis[curr])
    {
        bool got = false;
        ans.push_back(make(n, curr));
        vis[curr] = true;
        for (int i = 0; i < n && got == false; i++)
        {
            if ((1 << i) & curr)
            {
                if (!vis[curr - (1 << i)])
                {
                    curr = (curr - (1 << i));
                    got = true;
                    break;
                }
            }
            else
            {
                if (curr + (1 << i) < (1 << n) && !vis[curr + (1 << i)])
                {
                    curr += (1 << i);
                    got = true;
                    break;
                }
            }
        }
    }
    for (auto &val : ans)
        cout << val << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}