#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    vector<int> v(n, 0);
    for (auto &val : b)
        v[val % n]++;
    set<int> s;
    for (int i = 0; i < n; i++)
        if (v[i] > 0)
            s.insert(i);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int mod = a[i] % n;
        int need = n - mod;
        auto it = s.lower_bound(need);
        if (it == s.end())
            it = s.begin();
        int pt = *it;
        // cout << i << " " << need << " " << pt << endl;
        s.erase(it);
        mod += pt;
        ans.push_back(mod % n);
        v[pt]--;
        if (v[pt])
            s.insert(pt);
    }
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}