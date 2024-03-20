#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (n == 2)
    {
        LL diff = v.back() - v.front();
        if (diff != 0)
        {
            if (diff & 1ll)
            {
                cout << 2 << endl;
                cout << v.front() - diff << " " << v.back() + diff << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << v.front() - diff << " " << v.front() + (diff / 2ll) << " " << v.back() + diff << endl;
            }
        }
        else
        {
            cout << 1 << endl
                 << v.front() << endl;
        }
        return;
    }
    else
    {
        map<LL, LL> mp;
        for (int i = 1; i < n; i++)
            mp[v[i] - v[i - 1]]++;
        if (mp.size() > 2)
        {
            cout << 0 << endl;
        }
        else if (mp.size() == 1)
        {
            LL diff = v[1] - v[0];
            if (diff != 0)
            {

                cout << 2 << endl;
                cout << v.front() - diff << " " << v.back() + diff << endl;
            }
            else
            {
                cout << 1 << endl
                     << v.front() << endl;
            }
            return;
        }
        else
        {
            // mp.size() == 2
            if (((mp.begin()->first * 2ll) != (mp.rbegin()->first)) || (mp.rbegin()->first % 2) || (mp.rbegin()->second > 1))
            {
                cout << 0 << endl;
                return;
            }
            cout << 1 << endl;
            for (int i = 1; i < n; i++)
            {
                if ((v[i] - v[i - 1]) == mp.rbegin()->first)
                {
                    cout << v[i - 1] + mp.begin()->first << endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
/*
1
-> 2
=> 1

2
->1 1
-> 2 2
=>1*2 + 1 = 2

1 2
-> 2 3
-> 1*3 + 2 => 5

4
1 2 1
-> 2 3 2
-> 1*3*2 + 2*2 + 1
=> 6+4+1=>11

*/