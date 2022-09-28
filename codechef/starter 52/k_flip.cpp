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
        int c = n - k + 1;
        string s;
        cin >> s;
        int i = 0;
        while (i < n - k + 1 && c--)
        {
            while (i < n - k + 1 && s[i] == '0')
            {
                i++;
            }
            if (i >= n - k + 1)
            {
                break;
            }
            int curr_c = k, curr_i = i;
            while (curr_i < n && curr_c--)
            {
                if (s[curr_i] == '1')
                {
                    s[curr_i] = '0';
                    // i++;
                }
                else if (s[curr_i] == '0')
                {
                    s[curr_i] = '1';
                }
                curr_i++;
            }
            // i--;
        }

        cout << s << endl;
    }
    return 0;
}