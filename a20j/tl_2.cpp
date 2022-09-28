#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), v1(m);
    for(auto &val:v){cin>>val;}
    for(auto &val:v1){cin>>val;}
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    int tl = v[0];
    int limit=v[n-1];
    for (int i = v[0]; i < v[n-1]; i++)
    {
        int a = limit - i;
        if(2*a <= i)
        {
            tl=i;
            break;
        }
    }
    if(v1[0]<=tl)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<tl<<endl;
    }
    return 0;
}