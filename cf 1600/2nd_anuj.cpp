#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        vector<long long> even, odd;
        string s;
        cin >> s;
        for (auto &val : s)
        {
            int c = val - '0';
            if (c == 0)
                continue;
            if (c & 1)
                odd.push_back(c);
            else
                even.push_back(c);
        }
        if (even.size() && odd.size())
        {
            long long e = even[0];
            for (int i = 1; i < even.size(); i++)
                e *= even[i];
            long long o = odd[0];
            for (int i = 1; i < odd.size(); i++)
                o *= odd[i];
            cout << max(0ll, e - o) << " ";
        }
        else if (even.size())
        {
            long long e = even[0];
            for (int i = 1; i < even.size(); i++)
                e *= even[i];
            cout << e << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    return 0;
}