#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int ltrav(int ind, vector<int> &left, set<pair<int, int>> &s)
{
    if (left[ind] != -1)
        return left[ind];
    int ret = 0;
    if (s.find({ind, ind - 1}) != s.end())
        ret = 1 + ltrav(ind - 1, left, s);
    return left[ind] = ret;
}
int rtrav(int ind, vector<int> &right, set<pair<int, int>> &s)
{
    if (right[ind] != -1)
        return right[ind];
    int ret = 0;
    if (s.find({ind, ind + 1}) != s.end())
        ret = 1 + rtrav(ind + 1, right, s);
    return right[ind] = ret;
}
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++)
    {
        char ch = str[i - 1];
        if (ch == 'L')
            s.insert({i, i - 1});
        else
            s.insert({i - 1, i});
    }
    vector<int> left(n + 1, -1), right(n + 1, -1);
    left[0] = 0, right[n] = 0;
    for (int i = 0; i <= n; i++)
        ltrav(i, left, s);
    for (int i = n; i >= 0; i--)
        rtrav(i, right, s);
    vector<int> v(n + 1, 1);
    for (int i = 0; i <= n; i++)
        v[i] += (left[i] + right[i]);
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
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