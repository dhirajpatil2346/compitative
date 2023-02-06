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
        int ans = 0;
        int a, b;
        cin >> a >> b;
        // cout<<(a&1)<<endl;
        // cout<<(b&1)<<endl;
        for (int i = 31; i >= 0; i--)
        {
            if (((a & (1 << i)) && (b & (1 << i))))
            {
                // cout << "here" << endl;
                ans |= (1 << i);
            }
        }
        // cout << ans << endl;
        cout << (a ^ ans) + (b ^ ans) << endl;
    }
    return 0;
}
/*

0100
1001
0000

0110
1100
0100
*/