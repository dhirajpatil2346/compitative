#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
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

multiset<int> m[22], s;
void ins(int n)
{
    s.insert(n);
    for (int i = 0; i < 22; i++)
    {
        if ((1 << i) & n)
            m[i].insert(n);
    }
}
void rm(int n)
{
    s.erase(s.find(n));
    for (int i = 0; i < 22; i++)
    {
        if ((1 << i) & n)
            m[i].erase(m[i].find(n));
    }
}

int check(int n)
{
    for (int i = 21; i >= 0; i--)
    {
        // cout << i << " " << (!(1 << i) & n) << " " << m[i].size() << endl;
        if ((!((1 << i) & n)) && m[i].size() != 0)
        {
            // cout << "    " << i << endl;
            return i;
        }
    }
    return -1;
}

void process(int b)
{
    // cout << check(b) << endl;
    // char ch;
    // cin >> ch;
    int a = *m[check(b)].begin();
    // cout << a << " " << b << endl;
    rm(b), rm(a);
    ins(a & b), ins(b | a);
    // for (auto &val : s)
    //     cout << val << " ";
    // cout << endl;
}

void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ins(x);
    }
    // cout << "here" << endl;
    for (int i = 0; i < 22; i++)
    {
        // cout << i << " " << m[i].size() << endl;
    }
    // cout << check(123) << endl;
    while (s.size())
    {
        // cout << check(*prev(s.end())) << endl;
        if (check(*prev(s.end())) == -1)
        {
            ans += ((*prev(s.end())) * (*prev(s.end())));
            cout << (*prev(s.end())) << endl;
            rm(*prev(s.end()));
        }
        else
        {
            // for (auto &val : s)
            //     cout << val << " ";
            // cout << endl;
            // cout << (*prev(s.end())) << " : ";
            // cout << "processing" << endl;
            process(*prev(s.end()));
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}