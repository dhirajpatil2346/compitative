#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll z = 1e5 + 1;
    vector<ll> squares;
    map<ll, bool> m;
    map<ll, ll> sq;
    for (int i = 0; i <= z; i++)
    {
        ll k = i * 1ll * i;
        squares.push_back(k);
        sq[k]=i;
        m[k] = true;
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        bool got = false;
        for (int i = 0; i < squares.size(); i++)
        {
            if (squares[i] > n)
            {
                break;
            }
            ll req = n - squares[i];
            if (m[req])
            {
                cout << sq[squares[i]] << " " << sq[req] << endl;
                got = true;
                break;
            }
        }
        if (!got)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}