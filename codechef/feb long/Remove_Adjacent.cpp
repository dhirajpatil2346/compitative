#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    int cnt = 0;
    int j = 0;
    while (true)
    {
        sort(v.begin(), v.end());
        /*
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
        */
        cout<<v[j]<<"   "<<*v.rbegin()<<endl;
        if (v[j] == *v.rbegin())
        {
            cout << cnt << endl;
            break;
        }
        else
        {
            v.push_back(v[j] + v[j+1]);
            j+=2;
            cnt++;
        }
    }
    return 0;
}