#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 9;

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

const LL sz = 1e6 + 5;
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

vector<LL> p_pow(sz, 1);
const LL p = 137;

void solve()
{
    string s;
    cin >> s;
    int l = 0, r = s.length() - 1, n = s.length();
    while (l <= r)
        if (s[l] == s[r])
            l++, r--;
        else
            break;
    if (l > r)
    {
        cout << s << endl;
        return;
    }
    vector<LL> hashfor(n), hashback(n);
    LL curr_h = 0;
    for (LL i = 0; i < n; i++)
    {
        LL let = s[i] - 'a' + 1;
        curr_h = (curr_h + let * p_pow[i]) % mod;
        hashfor[i] = curr_h;
    }
    curr_h = 0;
    for (LL i = n - 1; i >= 0; i--)
    {
        LL let = s[i] - 'a' + 1;
        curr_h = (curr_h + let * p_pow[n - i - 1]) % mod;
        hashback[i] = curr_h;
    }
    LL o = -1, c = -1;
    for (LL i = l; i <= r; i++)
    {
        // check seg l to i
        LL hash = hashfor[i];
        if (l > 0)
            hash = (hash - hashfor[l - 1] + mod) % mod;
        LL hashb = hashback[l];
        if (i < (n - 1))
            hashb = (hashb - hashback[i + 1] + mod) % mod;
        // cout << i << " " << hash << " " << hashb << endl;
        LL pfused = l;
        LL pbused = n - i - 1;
        if (pfused <= pbused)
            hash = (hash * p_pow[abs(pfused - pbused)]) % mod;
        else
            hashb = (hashb * p_pow[abs(pfused - pbused)]) % mod;
        if (hash == hashb)
            o = i;
    }
    for (LL i = r; i >= l; i--)
    {
        // start from r  to i
        // i .... r
        LL hashb = hashback[i];
        if ((r + 1) < n)
            hashb = (hashb - hashback[r + 1] + mod) % mod;
        LL hash = hashfor[r];
        if (i > 0)
            hash = (hash - hashfor[i - 1] + mod) % mod;
        LL pfused = i;
        LL pbused = n - r - 1;
        if (pfused <= pbused)
            hash = (hash * p_pow[abs(pfused - pbused)]) % mod;
        else
            hashb = (hashb * p_pow[abs(pfused - pbused)]) % mod;
        if (hash == hashb)
            c = i;
    }
    string s1 = "", s2 = "", s3 = "", s4 = "";
    for (int i = 0; i < l; i++)
        s1.push_back(s[i]);
    for (int i = l; i <= o; i++)
        s2.push_back(s[i]);
    for (int i = c; i <= r; i++)
        s3.push_back(s[i]);
    for (int i = r + 1; i < n; i++)
        s4.push_back(s[i]);
    cout << s1 << ((s2.length() >= s3.length()) ? s2 : s3) << s4 << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}