#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int maxi(string &s1, string &s2)
{
    int i = 0;
    while (i < s1.length() && i < s2.length())
    {
        if (s1[i] == s2[i])
            i++;
        if (s1[i] > s2[i])
            return 0;
        else
            return 1;
    }
    if (i == s1.length())
        return 1;
    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<char> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    if (n == k)
        cout << v.back() << endl;
    else if (k == 1)
    {
        for (auto &val : v)
            cout << val;
        cout << endl;
    }
    else if (v.front() == v.back())
    {
        for (int i = 0; i < n; i += k)
            cout << v[i];
        cout << endl;
    }
    else if (v[0] != v[k - 1])
        cout << v[k - 1] << endl;
    else
    {

        // here v[0] == v[k-1]
        // if v[0] is exactly k
        // then check others are only one
        // if one follow routine
        // else add to 1st and cout
        // if not exactly k add to 1st and cout
        if (count(v.begin(), v.end(), v[0]) == k)
        {
            set<char> s;
            for (int i = k; i < n; i++)
                s.insert(v[i]);
            if (s.size() == 1)
            {
                for (int i = 0; i < n; i += k)
                {
                    cout << v[i];
                }
                cout << endl;
            }
            else
            {
                cout << v[0];
                for (int i = k; i < n; i++)
                    cout << v[i];
                cout << endl;
            }
        }
        else
        {
            cout << v[0];
            for (int i = k; i < n; i++)
                cout << v[i];
            cout << endl;
        }
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