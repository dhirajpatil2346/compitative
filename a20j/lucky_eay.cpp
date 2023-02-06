/*
4500
4744

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> ans;
void equal(string s, int four, int seven, int r)
{
    // cout << r << endl;
    if (s.length() == r)
    {
        if (four == seven)
        {
            ans.push_back(stoll(s, 0, 10));
        }
        return;
    }
    equal(s + '4', four + 1, seven, r);
    equal(s + '7', four, seven + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    string m = to_string(n);
    equal("", 0, 0, m.length());
    equal("", 0, 0, (m.length() + 1));
    equal("", 0, 0, (m.length() + 2));
    ll max = INT64_MAX;
    /*
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    */
    for (auto &val : ans)
    {
        if (val >= n)
        {
            max = min(val * 1ll, max);
        }
    }
    cout << max << endl;
    return 0;
}