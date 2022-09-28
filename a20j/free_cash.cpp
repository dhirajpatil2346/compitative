#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(1440);
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v[x * 60 + y]++;
    }
    int maxi = 1;
    for (auto &val : v)
    {
        maxi = max(val, maxi);
    }
    cout << maxi << endl;
    return 0;
}