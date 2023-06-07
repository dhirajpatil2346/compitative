#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solopal(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return (s1 == s);
}
set<LL> palnum;
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
        for (auto &valu : palnum)
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
    string s = "";
    vector<string> st;
    for (char i = '0'; i <= '9'; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            string h = "";
            h.push_back(i);
            h.push_back(j);
            st.push_back(h);
        }
    }
    set<string> nv;
    for (auto &val : st)
    {
        if (solopal(val))
            nv.insert(val);
    }
    for (int i = 0; i < st.size(); i++)
    {
        for (int j = 0; j < st.size(); j++)
        {
            for (char c = '0'; c <= '9'; c++)
            {
                string h = st[i];
                h.push_back(c);
                h += st[j];
                int pos = -1;
                for (int u = 0; u < h.length(); u++)
                    if (h[u] != '0')
                    {
                        pos = u;
                        break;
                    }
                if (pos == h.length())
                    continue;
                string p = "";
                for (int y = pos; y < h.length(); y++)
                    p.push_back(h[y]);
                h = p;
                if (solopal(h))
                    nv.insert(h);
            }
        }
    }
    // for (auto &val : nv)
    //     cout << val << " ";
    for (auto &val : nv)
    {
        LL num = 0;
        for (int i = 0; i < val.length(); i++)
        {
            num *= 10;
            num += (val[i] - '0');
        }
        if (num < (2 << 15))
            palnum.insert(num);
    }
    // cout << palnum.size() << endl;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}