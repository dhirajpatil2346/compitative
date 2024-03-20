#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
long calculateAmount(vector<int> prices)
{
    vector<long long> v;
    for (auto &val : prices)
        v.push_back(val);
    set<long long> s;
    long long ans = prices[0];
    s.insert(prices[0]);
    for (int i = 1; i < prices.size(); i++)
    {
        long long val = v[i];
        long long cost = max(0ll, val - (*s.begin()));
        ans += cost;
        s.insert(val);
    }
    long ret = ans;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    cout << calculateAmount(v) << endl;
    return 0;
}