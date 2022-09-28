#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &v, int l, int n)
{
    for (int i = n - 1; i > l; i--)
    {
        int temp = v[i];
        v[i] = v[i - 1];
        v[i - 1] = temp;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> ori(n);
    for(auto &val:ori)
    {
        cin>>val;
    }
    int maxi = ori[n-1]-ori[0];
    for (int i = 0; i < n; i++)
    {
        left_rotate(o,0,n);
    }
    
    return 0;
}