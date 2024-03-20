#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 10);
    vector<int> c(n);
    for (auto &val : c)
        cin >> val;
    int k;
    cin >> k;
    map<int, int> m;
    m[c[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        // 3 1 2 4
        if ((m.begin())->first <= c[i])
            continue;
        m[c[i]] = i;
    }
    // for (auto &val : m)
    //     cout << val.first << " " << val.second << endl;
    int freq = k / (m.begin()->first);
    v[0] += freq;
    v[(*m.begin()).second + 1] -= freq;
    k %= (*m.begin()).first;
    auto it = m.begin();
    it++;
    while (it != m.end())
    {
        // cout << k << endl;
        // i want value such that value + k >= it->first :: value >= it->first - k
        // cout << it->first << endl;
        auto iit = m.lower_bound(it->first - k);
        // searched is
        // cout << "searched is : " << (it->first - k) << endl;
        if (iit->first >= it->first)
            break;
        int prevcost = iit->first, prevup = iit->second;
        v[0]--, v[prevup + 1]++;
        k += prevcost;
        k -= it->first;
        v[0]++;
        v[it->second + 1]--;
        it++;
    }
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
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
/*
3 1 2 4


*/