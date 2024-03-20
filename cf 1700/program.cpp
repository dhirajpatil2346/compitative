#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int x = 0;
    vector<int> fact;
    for (auto &val : s)
    {
        if (val == '+')
            x++;
        else
            x--;
        fact.push_back(x);
    }
    vector<int> maxforward(n), minforward(n), maxbackward(n), minbackward(n);
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(fact[i], maxi);
        mini = min(fact[i], mini);
        maxforward[i] = maxi, minforward[i] = mini;
    }
    maxi = 0, mini = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '+')
        {
            maxi++;
            mini = min(0, mini + 1);
        }
        else
        {
            maxi = max(maxi - 1, 0);
            mini--;
        }
        maxbackward[i] = maxi, minbackward[i] = mini;
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int left = x - 2, right = y;
        int value = 0;
        if (left >= 0)
            value = fact[left];
        int rightmax = 0, rightmin = 0, leftmax = 0, leftmin = 0;
        if (y < n)
            rightmax = maxbackward[y] + value, rightmin = minbackward[y] + value;
        if (left >= 0)
            leftmax = maxforward[left], leftmin = minforward[left];
        vector<int> curr = {leftmin, leftmax, rightmax, rightmin};
        // cout << x << " " << y << " -- > ";
        // for (auto &val : curr)
        //     cout << val << " ";
        // cout << endl;
        sort(curr.begin(), curr.end());
        cout << curr.back() - curr.front() + 1 << endl;
    }
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
+  -  -  +  -  -  +  -
1  0  0  1  0  0  1  0
0 -1 -2 -1 -2 -2 -1 -2

*/