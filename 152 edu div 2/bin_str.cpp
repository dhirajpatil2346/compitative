#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL p = 31;
const LL m = 1e9 + 9;
vector<long long> p_pow(1e5 + 10);
void sieve()
{
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;
}
bool isp(string &s, int &l, int &r, set<LL> &m, LL &hash)
{
    vector<char> v;
    for (int i = l; i <= r; i++)
    {
        v.push_back(s[i]);
    }
    LL ch = hash;
    for (LL i = l; i <= r; i++)
    {
        ch = (ch - ((LL)(s[i] - '0' + 1) * p_pow[i]) ) % m;
        
    }
    sort(v.begin(), v.end());
    for (LL i = l, j = 0; i <= r; j++, i++)
    {
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    cout << endl;
    string s;
    cin >> s;
    LL hash = 0;
    for (int i = 0; i < s.length(); i++)
        hash = ((hash + s[i] - '0' + 1) * p_pow[i]) % m;
    int cp = 0;
    set<LL> m;
    for (int _ = 0; _ < q; _++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        isp(s, a, b, m, hash);
    }
    if (cp < q)
        cp++;
    cout << cp << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}