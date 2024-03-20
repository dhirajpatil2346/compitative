#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;

int block = 1;
struct query
{
    int L, R, ind, ans = 0;
    query(int l = 0, int r = 0, int i = 0) : L(l), R(r), ind(i) {}
};

bool cmp(query &a, query &b)
{
    if (((a.L) / block) != ((b.L) / block))
        return ((a.L) / block) < ((b.L) / block);
    return a.R < b.R;
}

void solve()
{
    LL n, q;
    cin >> n >> q;
    block = sqrt(n);
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<query> vp(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        // query z;
        query z(l, r, i);
        vp[i] = z;
    }
    sort(vp.begin(), vp.end(), cmp);
    // for (auto &val : vp)
    //     cout << val.L + 1 << " " << val.R + 1 << endl;
    int c = 0, L = 0, R = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < q; i++)
    {
        int l = vp[i].L, r = vp[i].R;
        while (r + 1 < R)
        {
            // take R back.. i don't need you
            R--;
            if (m[v[R]] == v[R])
                c--;
            m[v[R]]--;
            if (m[v[R]] == v[R])
                c++;
        }
        while (r >= R)
        {
            // take R forward .. i need you
            if (m[v[R]] == v[R])
                c--;
            m[v[R]]++;
            if (m[v[R]] == v[R])
                c++;
            R++;
        }
        while (l < L)
        {
            // take L back .. i need u
            L--;
            if (m[v[L]] == v[L])
                c--;
            m[v[L]]++;
            if (m[v[L]] == v[L])
                c++;
        }
        while (l > L)
        {
            // take L forward..i don't need u
            if (m[v[L]] == v[L])
                c--;
            m[v[L]]--;
            if (m[v[L]] == v[L])
                c++;
            L++;
        }

        vp[i].ans = c;
    }
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        ans[vp[i].ind] = vp[i].ans;
    }
    for (auto &val : ans)
        cout << val << endl;
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