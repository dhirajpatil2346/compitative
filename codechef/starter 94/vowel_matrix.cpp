#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
LL solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    int cnt = 0;
    for (auto val : s)
        if (vowel.find(val) != vowel.end())
            cnt++;
    if (cnt % k)
        return 0;
    vector<LL> options;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vowel.find(s[i]) != vowel.end())
            c++;
        // cout << i << " " << c << endl;
        if (c == k)
        {
            // cout << i << endl;
            cnt = 0;
            int j = i + 1;
            while (j < n && vowel.find(s[j]) == vowel.end())
                cnt++, j++;
            options.push_back(cnt);
            c = 0;
        }
    }
    // for (auto &val : options)
    //     cout << val << " ";
    // cout << endl;
    if (options.size())
        options.pop_back();
    for (auto &val : options)
        val++;
    LL ans = 1;
    for (auto &val : options)
        ans = (ans * val) % mod;
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