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
        bool norm = true;
        int i = 0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sc = 0;
        while (i < n)
        {
            if (norm)
            {
                while (i < n && s[i] == '0')
                {
                    i++;
                }
                while (i < n && s[i] == '1')
                {
                    i++;
                }
                if (i < n)
                {
                    sc++;
                }
            }
            else
            {
                // cout << "2nd" << endl;
                while (i < n && s[i] == '1')
                {
                    i++;
                }

                while (i < n && s[i] == '0')
                {
                    i++;
                }
                if (i < n)
                {
                    sc++;
                }
            }
            norm = !(norm);
        }
        cout << sc << endl;
    }
    return 0;
}
/*
010101
1010
101
10
01

*/