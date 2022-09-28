#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    map<int, stack<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]].push(i + 1);
    }
    bool got = false;
    return 0;
}