#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        ll maxi = v[n - 1];
        vector<ll> to_add;
        ll cnt = 1;
        ll i = 0;
        ll m = 0;
        if (k == 1)
        {
            int ele = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] != i + 1)
                {
                    ele = i + 1;
                    v.push_back(ele);
                    break;
                }
            }
            if (ele == 0)
            {
                cout << n - 1 << endl;
            }
            else
            {
                cout << *max_element(v.begin(), v.end()) - ele << endl;
            }
        }
        else
        {
            cnt = 2 * n;
            sort(v.rbegin(), v.rend());
            while (m < k - 1 && i < v.size())
            {
                if (v[i] == cnt)
                {
                    cnt--;
                }
                else
                {
                    i++;
                    to_add.push_back(cnt);
                    v.push_back(cnt);
                    m++;
                    cnt--;
                }
            }
            sort(v.begin(), v.end());
            ll maxi = *max_element(to_add.begin(), to_add.end());
            cnt = 1;
            k = 1;
            m = 0;
            i = 0;
            to_add.clear();
            while (m < k - 1 && i < v.size())
            {
                if (v[i] == cnt)
                {
                    cnt++;
                    i++;
                }
                else
                {
                    // cout <<v[i]<< cnt << endl;
                    i++;
                    to_add.push_back(cnt);
                    m++;
                    cnt--;
                }
            }
            int ele = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] != i + 1)
                {
                    ele = i + 1;
                    v.push_back(ele);
                    break;
                }
            }
            sort(v.begin(), v.end());
            if (ele == 0)
            {
                cout << v[n - 1] - 1 << endl;
            }
            else
            {
                cout << *max_element(v.begin(), v.end()) - ele << endl;
            }
        }
    }

    return 0;
}