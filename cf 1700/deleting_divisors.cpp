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

void solve()
{
    int n, c = 0;
    cin >> n;
    // vector<int> v(n + 1, 1);
    // for (int i = 1; i <= n; i++)
    //     for (int j = 2; j < i; j++)
    //         if (i % j == 0)
    //             if (v[i - j] == 1)
    //             {
    //                 c++;
    //                 cout << i << " " << j << endl;
    //                 v[i] = 0;
    //                 break;
    //             }
    // cout << c << endl;
    int bit = __builtin_popcount(n);
    if(bit==1 && n!=1)
    {
        if((int)(log2(n))&1)
            cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
    }
    else if (n & 1)
        cout << "Bob" << endl;
    else
        cout << "Alice" << Endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
for middle go anywhere you will get answer

full drives
go to right last if you are on left
go to left last if are on right


*/