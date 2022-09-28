#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int ret = 0;
        while (true)
        {
            // cout<<m<<"  "<<n<<endl;
            if (((m < 3) && (n<3)) || (m<1) || (n<1))
            {
                cout << ret << endl;
                break;
            }
            else if (m < n)
            {
                ret++;
                n -= 3;
                m--;
            }
            else
            {
                m-=3;
                n--;
                ret++;
            }
        }
    }
    return 0;
}