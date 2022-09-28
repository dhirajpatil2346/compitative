#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y, k, n;
    cin >> y >> k >> n;
    if (y >= n)
    {
        cout << -1 << endl;
    }

    else
    {

        int p = n - y;
        int r = 0;
        vector<int> vnl;
        if (y % k == 0)
        {
            r = k;
        }
        // cout<<k<< " "<<r%k<<endl;
        r = k - (y % k);
        // cout<<r<<endl;
        while (r <= p)
        {
            cout << r << " ";
            vnl.push_back(1);
            r += k;
            
        }
        if(vnl.size()==0)
            {
                cout<<-1<<endl;
            }

    }
    return 0;
}