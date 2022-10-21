#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // int n = 8;
        vector<string> v;
        for (int i = 0; i < 8; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        bool got = false;
        char ans = 'c';
        for (int i = 0; i < 8; i++)
        {
            string s = "";
            for (int j = 0; j < 8; j++)
            {
                s += v[j][i];
            }
            v.push_back(s);
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] == "RRRRRRRR")
            {
                got = true;
                ans = 'R';
                break;
            }
            if (v[i] == "BBBBBBBB")
            {
                got = true;
                ans = 'B';
                break;
            }
        }
        /*
        for (auto &val : v)
        {
            cout << val << endl;
        }
        */
        cout << ans << endl;
    }
    return 0;
}