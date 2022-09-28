#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    // cout << a << b << n << endl;
    string ans = to_string(a);
    bool fault = false;
    while (n--)
    {
        // cout << 0 << endl;
        int have = a * 10;
        int got = -1;
        for (int i = 0; i <= 9; i++)
        {
            if ((have + i) % b == 0)
            {
                got = i;
                break;
            }
        }
        if (got == -1)
        {
            fault = true;
            break;
        }
        else
        {
            a = 0;
            ans += to_string(got);
        }
    }
    if (fault)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}