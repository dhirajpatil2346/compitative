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

int kmp(string &s)
{
    vector<int> pi(s.size());
    for (int i = 1; i < s.length(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }
    int o = 0;
    for (int i = s.size() / 2, j = 1; i < s.size(); i++, j++)
        if (pi[i] == j)
            o = j;
    return pi.back();
}
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
    string s1 = "", s4 = "";
    for (int i = 0; i < l; i++)
        s1.push_back(s[i]);
    for (int i = r + 1; i < n; i++)
        s4.push_back(s[i]);
    string middle = "";
    for (int i = l; i <= r; i++)
        middle.push_back(s[i]);
    string a = middle, b = middle;
    reverse(b.begin(), b.end());
    string A = a + "$" + b;
    string B = b + "$" + a;
    A = A.substr(0, kmp(A)), B = B.substr(0, kmp(B));
    reverse(B.begin(), B.end());
    // cout << A << " " << B << endl;
    cout << s1 << ((A.length() > B.length()) ? A : B) << s4 << endl;
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