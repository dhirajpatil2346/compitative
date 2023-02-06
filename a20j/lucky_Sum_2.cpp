#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long strtoi(string s)
{
    long long num = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        num = num * 10 + (s[i] - '0');
    }
    // cout << num << endl;
    return num;
}
void createNum(vector<ll> &values, string s, ll n)
{
    if (s.length() == n)
    {
        values.push_back(strtoi(s));
        return;
    }

    string j = s;
    j += '4';
    createNum(values, j, n);
    string k = s;
    k += '7';
    createNum(values, k, n);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << strtoi("10110") << endl;
    vector<ll> values;
    ll x, y;
    cin >> x >> y;
    string s = to_string(x);
    ll len1 = s.length();
    s = to_string(y);
    ll len2 = s.length();
    for (ll i = len1; i <= len2 + 1; i++)
    {
        createNum(values, "", i);
    }
    sort(values.begin(), values.end());
    ll i = 0;
    while (i < values.size() && values[i] < x)
    {
        i++;
    }
    ll start = i;
    i = values.size() - 1;
    while (i >= 0 && values[i] > y)
    {
        i--;
    }
    ll end = i;
    ll curr = x;
    long long ans = 0;
    /*
        for ( i = start; i <= values.size() - 1; i++)
        {
            cout << values[i] << " ";
        }
        cout << endl;
    */
    for (i = start; i <= values.size() - 1; i++)
    {
        // cout << curr << " ";
        if (curr > y)
        {
            break;
        }
        ll diff = min(y - curr, values[i] - curr);
        diff++;
        // cout << diff << " " << values[i] << endl;
        ans += diff * 1ll * values[i];
        curr = values[i] + 1;
    }
    cout << ans << endl;
    return 0;
}
