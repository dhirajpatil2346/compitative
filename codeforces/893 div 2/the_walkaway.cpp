#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, m, d;
    cin >> n >> m >> d;
    vector<LL> v(m);
    for (auto &val : v)
        cin >> val;
    int start = 0;
    if (v[0] != 1)
    {
        start = 1;
        vector<LL> h = {1};
        for (auto &val : v)
            h.push_back(val);
        v = h;
    }
    LL def = (n - v.back()) / d;
    vector<LL> value(v.size(), 1);
    for (int i = 0; i < value.size(); i++)
    {
        LL bc = 0;
        if (i > 0)
            bc = v[i - 1];
        LL mk = v[i] - bc - 1;
        mk /= d;
        value[i] += mk;
    }
    cout << "values are : ";
    for (auto &val : value)
        cout << val << " ";
    cout << endl;
    LL prev = accumulate(value.begin(), value.end(), def);
    vector<LL> front = value, back = value;
    for (int i = 1; i < front.size(); i++)
        front[i] += front[i - 1];
    for (int i = back.size() - 2; i >= 0; i--)
        back[i] += back[i + 1];
    cout << "front are : ";
    for (auto &val : front)
        cout << val << " ";
    cout << endl;
    cout << "back are : ";
    for (auto &val : back)
        cout << val << " ";
    cout << endl;
    cout << "ARRAY is : " << endl;

    map<LL, int> track;
    for (int i = start; i < v.size(); i++)
    {
        LL curr = 1;
        if (i > 0)
            curr += front[i - 1];
        if (i < (m - 1))
            curr += back[i + 1];
        cout << curr << endl;
        LL prv = 0;
        if (i > 0)
            prv = v[i - 1] + 1;
        LL nxt = n + 1;
        if (i < (m - 1))
            nxt = v[i + 1] - 1;
        if (prv <= 1)
        {
            curr++;
            prv++;
        }
        LL inbet = nxt - prv + 1;
        if (inbet >= 0)
            curr += inbet / d;
        track[curr]++;
        cout << i << " " << inbet << " " << curr << endl;
    }
    cout << "ans is  : ";
    cout << track.begin()->first << " " << track.begin()->second << endl;
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