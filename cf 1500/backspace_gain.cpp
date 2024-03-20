#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    map<char, vector<int>> m;
    vector<int> pos;
    for (int i = 0; i < s1.length(); i++)
        m[s1[i]].push_back(i);
    for (int i = 0; i < s1.length(); i++)
        if ((i != 1) && (s1[i] == s2[0]))
            pos.push_back(i);
    for (int _ = 0; _ < pos.size(); _++)
    {
        int last_i = pos[_];
        int rj = 1;
        bool valid = true;
        while (valid && rj < s2.length())
        {
            int ind = lower_bound(m[s2[rj]].begin(), m[s2[rj]].end(), last_i + 1) - m[s2[rj]].begin();
            if (ind == m[s2[rj]].size())
            {
                valid = false;
                continue;
            }
            if (m[s2[rj]][ind] == (last_i + 1))
            {
                last_i = m[s2[rj]][ind];
                rj++;
                continue;
            }
            ind = lower_bound(m[s2[rj]].begin(), m[s2[rj]].end(), last_i + 3) - m[s2[rj]].begin();
            if (ind == m[s2[rj]].size())
            {
                valid = false;
                continue;
            }
            else
            {
                last_i = m[s2[rj]][ind];
                rj++;
            }
        }
        if (rj != s2.length())
            continue;
        return true;
    }
    return false;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}