#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        vector<ll> zeroes;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zeroes.push_back(i);
            }
        }
        zeroes.push_back(n);
        ll sum = 0;
        for (int i = 0; i < zeroes[0]; i++)
        {
            sum += v[i];
        }

        if (zeroes.size() != 0)
        {
            ll start = zeroes[0];
            ll l = zeroes.size();
            for (ll i = 0; i < l - 1; i++)
            {
                // cout << start << endl;
                vector<ll> v1;
                for (ll j = start; j < zeroes[i + 1]; j++)
                {
                    v1.push_back(v[j]);
                }
                // cout << "v1 is --> ";
                for (auto &val : v1)
                {
                    // cout << val << " ";
                }
                // cout << endl;
                sort(v1.rbegin(), v1.rend());
                if (v1.size() > 1)
                {
                    for (ll j = 0; j < v1.size() - 1; j++)
                    {
                        sum += v1[j];
                    }
                }
                ll z = start;
                for (ll j = 0; j < v1.size(); j++)
                {
                    v[z++] = v1[j];
                }
                for (auto &val : v)
                {
                    // cout << val << " ";
                }
                // cout << endl;
                start = zeroes[i + 1];
            }
        }
        cout << sum << endl;
    }
    return 0;
}