#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p = 0, big, small;
    cin >> n >> m;
    if (n > m)
    {
        big = n;
        small = m;
    }
    else
    {
        big = m;
        small = n;
    }
    // cout<<"big is: "<<big<<" small is: "<<small<<endl;
    // if (n == 1 && m == 1)
    // {
    //     cout << 2 << endl;
    //     return 0;
    // }
    for (int a = 0; a <= n; a++)
    {
        for (int b = 0; b <= m; b++)
        {
            // if(a<=b){
            if (((pow(a, 2) + b) == n) && ((a + pow(b, 2)) == m)) //|| (((pow(a, 2) + b) == m) && ((a + pow(b, 2)) == n)))
            {
                // cout<<a<<"  "<<b<<endl;
                p++;
            }
            // }
        }
    }

    cout << p;
    return 0;
}