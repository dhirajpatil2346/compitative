#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int pos1 = n - 1;
        int inc = 1;
        int c = 0;
        int need = 0;
        while (true)
        {
            if (c + inc > k)
            {
                need = -k + (c + inc);
                break;
            }
            else if (c + inc == k)
            {
                break;
            }
            else
            {
                pos1--;
                c += inc;
                inc++;
            }
        }
        // cout << pos1 << " " << need+1 << endl;
        string s = "";
        for (int i = 0; i < n; i++)
        {
            s += 'a';
        }
        s[pos1 - 1] = 'b', s[pos1 + need] = 'b';
        cout << s << endl;
    }
    return 0;
}