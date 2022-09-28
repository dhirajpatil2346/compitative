#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ws = INT_MAX;
        for (int i = 0; i < n - k + 1; i++)
        {
            int curr = 0;
            for (int j = 0; j < k; j++)
            {
                if (s[i + j] == 'W')
                {
                    curr++;
                }
            }
            ws = min(ws, curr);
        }
        cout << ws << endl;
    }
    return 0;
}