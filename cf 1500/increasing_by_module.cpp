#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (auto &val : v)
        cin >> val;
    int pt = 0;
    vector<long long> lis = {v[0]};
    for (int i = 1; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        cout << i << " " << it << endl;
        if (it == lis.size())
        {
            pt = i;
            lis.push_back(v[i]);
        }
        else if (it == (lis.size() - 1))
        {
            lis[it] = v[i];
            // pt = i;
        }
        else
            lis[it] = v[i];
    }
    cout << lis.size() << endl;
    for (auto &val : lis)
        cout << val << " ";
    cout << endl;
    lis.clear();
    lis = {v[0]};
    for (int i = 1; i <= pt; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if (it == lis.size())
        {
            lis.push_back(v[i]);
        }
        else
            lis[it] = v[i];
    }
    for (auto &val : lis)
        cout << val << " ";
    cout << endl;
    vector<int> vn(n);
    for (int i = 0, s = 0; i < n; i++)
    {
        if (s == lis.size())
            vn[i] = lis.back();
        else
        {
            if (lis[s] == v[i])
            {
                vn[i] = lis[s];
                s++;
            }
            else if (s == 0)
            {
                vn[i] = 0;
            }
            else
                vn[i] = lis[s - 1];
        }
    }
    for (auto &val : vn)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
lis ==> 0 1 3
0 6 1 3 2
0 0 1 3 3
0 1 0 0 1

lis => 0 4 6
10 10
5 0 5 9 4 6 4 5 0 0
0 0 5 9 9 9 9 9 9 9 
5 0 0 0 5 3 5 4 9 9 
*/