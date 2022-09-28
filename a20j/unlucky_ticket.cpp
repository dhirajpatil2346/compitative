#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v(n), v1(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = s[i];
    }
    int k = n;
    for (int i = 0; i < n; i++)
    {
        v1[i] = s[k++];
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    for (auto &val : v)
    {
        //cout << val;
    }
    //cout << endl;
    for (auto &val : v1)
    {
        //cout << val;
    }
    //cout<<endl;
    bool got = false;
    if (v[0] > v1[0])
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= v1[i])
            {
                //cout<<v[i]<<"   "<<v1[i]<<endl;
                got = true;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= v1[i])
            {
                //cout<<"2nd"<<endl;
                //cout<<v[i]<<"   "<<v1[i]<<endl;
                got = true;
                break;
            }
        }
    }
    if (got)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}