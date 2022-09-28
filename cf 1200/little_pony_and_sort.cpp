#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int p = -1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            p = i;
            break;
        }
    }
    // cout << p << endl;
    vector<int> vn;
    if (p != -1)
    {
        for (int i = p; i < n ; i++)
        {
            vn.push_back(v[i]);
        }
        for (int i = 0; i < p; i++)
        {
            vn.push_back(v[i]);
        }
        for (auto &val : vn)
        {
            // cout << val << " ";
        }
        cout << endl;
        sort(v.begin(), v.end());
        if (v == vn)
        {
            cout << n - p << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}