#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool ispali(int i, int j, string &s)
{
    while (i < j)
        if (s[i] != s[j])
            return false;
        else
            i++, j--;
    return true;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length(), m1 = 0, m2 = 0;
    vector<vector<int>> v(26);
    for (int i = 0; i < n; i++)
        v[s[i] - 97].push_back(i);
    int I = 0, J = n - 1;
    while (I <= J && s[I] == s[J])
        I++, J--;
    int t1 = I - 1, t2 = J + 1;
    cout << t1 << " " << t2 << endl;
    vector<int> v1, v2;
    for (int i = upper_bound(v[s[t1 + 1] - 97].begin(), v[s[t1 + 1] - 97].end(), t1) - v[s[t1 + 1] - 97].begin(); i < v[s[t1 + 1] - 97].size(); i++)
    {
        // cout << v[s[t1 + 1] - 97][i] << " ";
        // cout << i << endl;
        if (v[s[t1 + 1] - 97][i] >= (t2 - 1))
            break;
        v1.push_back(v[s[t1 + 1] - 97][i]);
    }
    if (v1.size())
        reverse(v1.begin(), v1.end());
    for (auto &val : v1)
        if (ispali(t1 + 1, val, s))
        {
            m1 = val - (t1 + 1) + 1;
            break;
        }
    for (int i = upper_bound(v[s[t2 - 1] - 97].begin(), v[s[t2 - 1] - 97].end(), t1) - v[s[t2 - 1] - 97].begin(); i < v[s[t2 - 1] - 97].size(); i++)
    {
        if (v[s[t2 - 1] - 97][i] >= (t2 - 1))
            break;
        v2.push_back(v[s[t2 - 1] - 97][i]);
    }
    for (auto &val : v2)
        cout << val << " ";
    cout << endl;
    for (auto &val : v2)
        if (ispali(val, t2 - 1, s))
        {
            m2 = val - (t1 + 1) + 1;
            break;
        }
    cout << m1 << " " << m2 << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}