#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll strtoi(string s)
{
    ll num = 0;

    for (int i = 0; i < int(min(3, int(s.length()))); i++)
    {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

ll last(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n % 1000;
    }
    ll res = last(n, k / 2);
    if (k % 2)
    {
        return ((res % 1000) * (res * 1000) * (n % 1000)) % 1000;
    }
    else
    {
        return ((res % 1000) * (res * 1000)) % 1000;
    }
}

ll first(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    else if (k == 1)
    {
        string j = to_string(n);
        string s = "";
        for (int i = 0; i < int(min(3, int(s.length()))); i++)
        {
            s += j[i];
        }
        ll m = strtoi(s);
        return m % 1000;
    }
    ll res = first(n, k / 2);
    if (k % 2)
    {
        string j = to_string(res);
        string s = "";
        for (int i = 0; i < int(min(3, int(s.length()))); i++)
        {
            s += j[i];
        }
        ll m = strtoi(s);
        
    }
    else
    {
        return
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    return 0;
}