#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0;
        int q = 0, a = 0;
        bool fault = false;
        while (i < n)
        {
            if (s[i] == 'Q')
            {
                q++;
            }
            else if (s[i] == 'A')
            {
                a++;
                if (q > 0)
                {
                    q--;
                    a--;
                }
            }
            i++;
        }
        if (q == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}