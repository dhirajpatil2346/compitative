#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long maxi =INT_MIN;
    vector<long long> v(n);
    for (auto &val : v)
    {
        // cout<<"enter : ";
        cin >> val;
        maxi = max(maxi, val);
    }
    vector<vector<long long>> parent(maxi + 1);
    vector<bool> primes(maxi + 1, true);
    for (long long i = 2; i <= maxi; i++)
    {
        if (!primes[i])
        {
            continue;
        }
        // cout<<i<<endl;
        for (long long j = 2*i; j <= maxi; j += i)
        {
            parent[j].push_back(i);
            primes[j] = false;
        }
    }
    long long z=0;
    /*
    for(auto &val:parent)
    {
        cout<<z<<"  -->     ";
        z++;
        for(auto &valu:val)
        {
            cout<<valu<<" ";
        }
        cout<<endl;
    }
    */
    for (long long i = 0; i < n; i++)
    {
        if (parent[v[i]].size() == 1)
        {
            long long c=1;
            long long j=parent[v[i]][0];
            while(j<=v[i])
            {
                j*=parent[v[i]][0];
                c++;
                // cout<<c<<"  "<<j<<endl;
            }
            long long z = c + 1;
            if(c==3)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}