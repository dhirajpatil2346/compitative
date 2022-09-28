#include<bits/stdc++.h>
using namespace std;
int retsum(int n)
{
    n--;
    return ((n*(n+1))/2);
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            m[x]++;
        }
        int sum=0;
        for(auto &val:m)
        {
            sum+=retsum(val.second);
        }
        cout<<sum<<endl;
    }
    return 0;
}