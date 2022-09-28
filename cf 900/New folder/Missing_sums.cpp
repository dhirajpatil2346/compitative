#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if (x == 1)
        {
            cout << 1 << endl;
        }
        if (x == 2)
        {
            cout << "1 5" << endl;
        }
        if (x >= 3)
        {
            vector<int> v(x);
            v[0]=1;
            v[1]=4;
            v[2]=9;
            for (int i = 3; i < x; i++)
            {
                v[i]=v[i-1]+v[i-2];
            }
            for (int i = 0; i < x; i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}