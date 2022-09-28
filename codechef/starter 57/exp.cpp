#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> v;
        vector<char> sign;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                sign.push_back(s[i]);
            }
            else
            {
                v.push_back(s[i]);
            }
        }
        sort(v.rbegin(), v.rend());
        sort(sign.begin(), sign.end());
        /*
        for(auto &val:v)
        {
            cout<<val;
        }
        cout<<endl;
        for(auto &val:sign)
        {
            cout<<val;
        }
        cout<<endl;
        */
        int z = v.size() - sign.size();
        for (int i = 0; i < z; i++)
        {
            cout << v[i];
        }
        for (int i = 0, k = z; i < sign.size(); i++, k++)
        {
            cout << sign[i] << v[k];
        }
        cout << endl;
    }
    return 0;
}