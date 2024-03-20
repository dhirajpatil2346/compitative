#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    for (auto &val : start)
        cin >> val;
    int x;
    cin >> x;
    vector<int> end(x);
    for (auto &val : end)
        cin >> val;
    for (int i = 0; i < n; i++)
        if (start[i] >= end[i])
            swap(start[i], end[i]);
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
        vp[i].first = start[i], vp[i].second = end[i];
    sort(vp.begin(), vp.end());
    x = 0;
    int i = 0;
    while (i < n)
    {
        x++;
        int pt = vp[i].second;
        while (i < n && vp[i].first <= pt)
            i++;
    }
    cout << x << endl;
    return 0;
}