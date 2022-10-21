#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v(2);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                v[1]++;
            }
            else
            {
                v[0]++;
            }
        }
        if (n % 2 == 0)
        {
            if (v[0] % 2 == 0 && v[1] % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}