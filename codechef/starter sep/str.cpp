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
        vector<pair<pair<int, int>, int>> v;
        int b = 0;
        int c = 0;
        int start = 1, end = 0;
        int laststart = 0;
        bool got = false;
        while (true)
        {
            int c = 0;
            int cgot = false;
            if (got)
            {
                break;
            }
            int k = start;
            for (int i = start - 1; i < n; i++)
            {
                if (s[i] == '0')
                {
                    c--;
                }
                else
                {
                    s[i] = '0';
                    c++;
                }
                if (c == 0)
                {
                    b = i;
                    cgot = true;
                }
                else if (i == n - 1 && !cgot)
                {
                    got = true;
                    break;
                }
            }
            if (got)
            {
                break;
            }
            end = b + 1;
            v.push_back({{start - laststart, end - laststart}, 0});
            start = end;
            laststart = end;
            if (b == n - 1)
            {
                break;
            }
        }
        int p = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                p = i;
                break;
            }
        }
        int o;
        if (p == -1)
        {
            o = 1;
        }
        else
        {
            o = n - p;
        }
        cout << o << " " << v.size() << endl;
        for (auto &val : v)
        {
            cout << val.first.first << " " << val.first.second << " " << val.second << endl;
        }
    }
    return 0;
}