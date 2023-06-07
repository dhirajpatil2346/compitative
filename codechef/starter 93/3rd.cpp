#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
set<string> st;
set<LL> sti;
void gene(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (s1 == s)
        st.insert(s);
    if (s.size() == 5)
        return;
    for (char i = '1'; i <= '9'; i++)
    {
        string h = s;
        h.push_back(i);
        gene(h);
    }
}

void solve()
{
    map<LL, LL> m;
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < n; i++)
    {
        LL x = v[i];
        m[x]++;
    }
    LL ans = 0;
    for (auto &val : m)
    {
        for (auto &valu : sti)
        {
            if ((val.first ^ valu) < val.first)
                continue;
            if (m.find(val.first ^ valu) == m.end())
                continue;
            // cout << val.first << " " << (val.first ^ valu) << endl;
            if (val.first != (val.first ^ valu))
                ans += val.second * m[val.first ^ valu];
            else
            {
                ans += ((val.second) * (val.second + 1)) / 2;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    gene("1");
    gene("2");
    gene("3");
    gene("4");
    gene("5");
    gene("6");
    gene("7");
    gene("8");
    gene("9");
    for (auto &val : st)
    {
        LL a = 0;
        for (int i = 0; i < val.length(); i++)
        {
            a *= 10;
            a += (val[i] - '0');
        }
        if ((a < (1 << 15)))
            sti.insert(a);
    }
    // cout << sti.size() << endl;
    // for (auto &val : sti)
    //     cout << val << " "
    //          << "";
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}