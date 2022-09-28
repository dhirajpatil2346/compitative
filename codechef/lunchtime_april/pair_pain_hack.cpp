#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        vector<int> v(n);
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i] = x;
            if (x == 1)
            {
                cnt += n - i - 1;
            }
            else if (x == 2)
            {
                n2++;
            }
        }
        int v2=0;
        if(n2>=1){
        int v2 = (n2) * (n2 - 1) / 2;
        // cout<<cnt<<"  "<<v2<<endl;
        }
        cout << cnt + v2 << endl;
    }
    return 0;
}