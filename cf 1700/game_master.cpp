#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
string solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    vector<pair<int, int>> sa, sb;
    for (int i = 0; i < n; i++)
        sa.push_back({a[i], i}), sb.push_back({b[i], i});
    sort(sa.begin(), sa.end()), sort(sb.begin(), sb.end());
    string str = "";
    for (int i = 0; i < n; i++)
        str.push_back('1');
    set<int> remain, curr;
    for (int i = 0; i < n - 1; i++)
    {
        remain.insert(sa[i].second);
        remain.insert(sb[i].second);
        curr.insert(sa[i].second);
        curr.insert(sb[i].second);
        if (curr.size() == (i + 1))
        {
            while (remain.size())
            {
                str[*(remain.begin())] = '0';
                remain.erase(remain.begin());
            }
        }
    }
    return str;
    return "";
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