#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

char parent(char c, map<char, char> &par)
{
    if (par[c] == c)
        return c;
    return parent(par[c], par);
}

void make(char c1, char c2, map<char, char> &par)
{
    par[c1] = parent(c2, par);
}

int solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        if (a[i] > b[i])
            return -1;
    set<char> to_change;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            to_change.insert(b[i]);
    map<char, char> par;
    for (char p = 'a'; p <= 'z'; p++)
        par[p] = p;
    // sort(to_change.begin(), to_change.end());
    map<char, vector<char>> dict;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            dict[a[i]].push_back(i);
    set<char> vis;
    int ans = 0;
    for (auto &val : to_change)
    {
        set<char> st;
        for (int i = 0; i < n; i++)
            if (b[i] == val && b[i] != a[i])
                st.insert(parent(a[i], par));
        // cout << val << " " << st.size() << endl;
        // for (auto &valu : st)
        //     cout << valu << " ";
        // cout << endl;
        ans += st.size();
        for (auto &valu : st)
            make(valu, val, par);
    }
    return ans;
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
        cout << solve() << endl;
    }
    return 0;
}