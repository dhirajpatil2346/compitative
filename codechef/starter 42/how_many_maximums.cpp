#include <bits/stdc++.h>
using namespace std;

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
        vector<int> v(n + 1);
        v[0] = n;
        int curr = n;
        int j = 1; // for vector
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                v[j] = ++curr;
            }
            else
            {
                v[j] = --curr;
            }
            j++;
        }
        sort(v.begin(), v.end());
        int maxi = v[n];
        int c = 0;
        for (auto &val : v)
        {
            if (val == maxi)
            {
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}