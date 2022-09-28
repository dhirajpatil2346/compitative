#include <bits/stdc++.h>
using namespace std;

int mex(int v[], int size)
{
    // int size = v.size();
    if (v[0] != 0)
    {
        // cout<<"first"<<endl;
        return 0;
    }
    for (int i = 1; i < size; i++)
    {
        if (v[i] - v[i - 1] > 1)
        {
            // cout<<"2nd"<<endl;
            return v[i - 1] + 1;
        }
    }

    return v[size - 1] + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = n * 2;
        // vector<int> v(k);
        int v[k];
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            v[i] = x;
        }
        sort(v, v + n);
        // vector<int> f(n), z(n);
        int f[n], z[n];
        for (int i = 0, j = 0; j < k;)
        {
            f[j] = v[i];
            i += 2;
            j++;
        }
        for (int i = 1, j = 0; i < k;)
        {
            z[j] = v[i];
            i += 2;
            j++;
        }
        /*
        for(auto &l:v)
        {
            cout<<l<<' ';
        }
        cout<<endl;
        for(auto &l:f)
        {
            cout<<l<<' ';
        }
        cout<<endl;
        for(auto &l:z)
        {
            cout<<l<<' ';
        }
        cout<<endl;
        */
        // cout<<mex(f)<<endl<<mex(z)<<endl;
        if (mex(f, n) != mex(z, n))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}