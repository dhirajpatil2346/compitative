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
        int ws = 0;
        int pi = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'W')
            {
                ws++;
            }
        }
        pi = 0;
        int mini = ws;
        for (int i = k; i < n; i++)
        {
            if (ws && s[pi] == 'W')
            {
                ws--;
            }
            if(s[i]=='W')
            {
                ws++;
            }
            mini = min(mini, ws);
            pi ++;
        }
        cout << mini << endl;
    }
    return 0;
}