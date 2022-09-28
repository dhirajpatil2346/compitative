#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c = 0;
    cin >> n;
    vector<int> v, v1, v1r;
    /*
    cin>>arr[0];
    for (int i = 1; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]>arr[i-1]){
            c++;
        }
    }
    */
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        v1.push_back(x);
    }
    sort(v1.begin(), v1.end());
    for (auto it = v1.rbegin(); it != v1.rend(); it++)
    {
        v1r.push_back(*it);
    }
    /*
    for (int i = 0; i < n; i++)
    {
        // cout<<v[i]<<"   "<<v1[i]<<"    "<<v1r[i]<<"  "<<endl;
    }
    */
    if (v1r == v)
    {
        cout << v.size() - 1;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (v[i] >= v[i - 1])
            {
                // cout<<v[i]<<" ";
                c++;
            }
        }
        cout<<c;
    }
    return 0;
}