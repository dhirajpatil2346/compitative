#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int size = n / 2;
        vector<char> start(size), end(size);
        for (int i = 0; i < size; i++)
        {
            start[i] = s[i];
        }
        for (int i = n - 1, j = 0; j < size; i--, j++)
        {
            end[j] = s[i];
        }
        int diff = 0;
        bool got = true;
        for (int i = 0; i < size; i++)
        {
            if (start[i] != end[i])
            {
                diff++;
                if (diff > m)
                {
                    cout << "NO" << endl;
                    got = false;
                    break;
                }
            }
        }
        if (got)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}