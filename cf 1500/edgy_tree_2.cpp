#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL f(int sc, int par, vector<vector<int>> &v, set<pair<int, int>> &s)
{
    LL ret = 1;
    for (auto &child : v[sc])
    {
        if (child == par)
            continue;
        int x = (f(child, sc, v, s));
        if (s.find({child, sc}) != s.end())
            ret += x;
    }
    cout << "--> " << sc << " " << par << " " << ret << endl;
    return ret;
}
void calc(vector<int> v, bool one, bool two, set<vector<int>> &s)
{
    // cout << one << endl;
    if (v.size() == 5)
    {
        if (one && two)
            s.insert(v);
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        vector<int> l = v;
        l.push_back(i);
        calc(l, one | (i == 1), two | (i == 2), s);
    }
}
LL ret(LL options, LL k)
{
    // options ^ k - 2 * ((options-1)^k) + 1
    LL r = 1;
    for (int i = 0; i < k; i++)
        r *= options;
    cout << "r is : " << r << endl;
    LL R = 1;
    for (int i = 0; i < k; i++)
        R *= (options - 1);
    cout << "R is : " << R << endl;
    R += R;
    r -= R;
    r++;
    return r;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1);
    set<pair<int, int>> s;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1)
        {
            s.insert({x, y});
            s.insert({y, x});
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    set<vector<int>> s1;
    vector<int> blank;
    calc(blank, false, false, s1);
    cout << s1.size() << endl;
    LL options = n;

    //     LL ans = 0;
    //     queue<int> q;
    //     vector<bool> vis(n + 1, false);
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (vis[i])
    //             continue;
    //         q.push(i);
    //         vis[i] = true;
    //         while (!q.empty())
    //         {
    //             if (options <= 1)
    //                 break;
    //             int f = q.front();
    //             q.pop();
    //             for (auto &child : v[f])
    //             {
    //                 if (child == f)
    //                     continue;
    //                 if (vis[child])
    //                     continue;
    //                 q.push(child);
    //                 vis[child] = true;
    //                 cout << options << endl;
    //                 ans += ret(options, k);
    //                 cout << ans << endl;
    //                 options--;
    //             }
    //         }
    //     }
    //     cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1 2
2 3
3 4
are edges
size is 4
1 2 with 1 2 3 4 => 32 * 4 = 128
1112
1113
1114
1122
1123
1124
1222
1223
1224
1233
1234
1333
1344


2 3 with 2 3 4 => 18 * 4 = 72
3 4 with 3 4 => 4*4=>16



*/
/*
3^5 - 2 - all are non element


*/
/*
3^5 total = 243
eleminate proper singles = 1
net we have 242
now edge faulty is 2 3
so 2 ^ 5 should be eleminated i.e. 242  - 32 = 210
1st testcase
all are proper so 4^4 - single prop = 252



*/