#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int n = max(a, b), m = min(a, b);
        if (a == 1 && b == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            long long z = 2 * 1ll * m + n - 2;
            cout << z << endl;
        }
    }
    return 0;
}
// /home/dhirajpatil2346/Competitive programming/codeforces/816 div 2/crossmarket.cpp