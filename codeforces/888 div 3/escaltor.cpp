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
    LL maxi = n * (n + 1);
    maxi /= 2ll;
    if (v.back() > maxi)
    {
        cout << "NO" << endl;
        return;
    }
    LL res = 0;
    if (v[0] != 1)
    {
        res = v[0];
        set<LL> s;
        stack<LL> st;
        st.push(v[0]);
        for (int i = 1; i < n; i++)
        {
            LL diff = v[i] - st.top();
            if (diff > n || s.find(diff) != s.end())
            {
                cout << "NO" << endl;
                return;
            }
        }
        LL z = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
            {
                z += i;
            }
        if (z == res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        set<LL> s;
        stack<LL> st;
        st.push(v[0]);
        for (int i = 1; i < n; i++)
        {
            LL diff = v[i] - st.top();
            if ((diff > n) || s.find(diff) != s.end())
            {
                if (res != 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    res = diff;
                }
            }
            else
            {
                s.insert(diff);
                st.push(v[i]);
            }
        }
        LL z = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
            {
                z += i;
            }
        if (z == res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
6 2 4 3
1 5 3 7
*/