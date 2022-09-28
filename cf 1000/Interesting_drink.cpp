#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    vector<int> v1(m);
    for (auto &val : v1)
    {
        cin >> val;
    }
    vector<int> v2 = v1;
    sort(v2.begin(), v2.end());
    /*
    for(auto &val:v2)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    */
    map<int, int> mp;
    int i = 0; // j is for vector v
        int curr = 0;
    for (int j = 0; j < m; j++)
    {
        int key = v2[j];
        while (i < n && v[i] <= key)
        {
            curr++;
            i++;
        }
        mp[key] = curr;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<mp[v1[i]]<<endl;
    }
    
    return 0;
}