#include <bits/stdc++.h>
using namespace std;

int binexpo (int n,int k)
{
    n=n%10;
    if(k==0){return 1;}
    int res = binexpo(n,k/2);
    if(k%2)
    {
        return res * res * n;
    }
    else
    {
        return res*res;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if(k!=0){
        cout << binexpo(n, k) % 10 << endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
    return 0;
}