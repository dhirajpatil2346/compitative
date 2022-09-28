#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        /* code */

        int m;
        cin >> m;
        int mod1 = 0,mod2=0;
        for (int i = 0; i < m; i++)
        {
            long long y;
            cin>>y;
            if (y % 3 == 1)
            {
                mod1++;
            }
            else if (y % 3 == 2)
            {
                mod2++;
            }
        }
        // cout<<mod1<<"   "<<mod2<<endl;
        if (mod1 ==mod2)
        {
            cout << mod1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}