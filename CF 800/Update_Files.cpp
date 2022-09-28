#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long total = 1, inc = 1, curr = 0;
        while (true)
        {
            if (total >= k)
            {
                break;
            }
            else
            {
                total *= 2;
                curr++;
            }
        }
        // cout<<total<<"   "<<curr<<endl;
        // 
        // 
        n-=total;
        if(n<=0){
            curr=curr;
        }
        else if(n%k==0)
        {
            curr+=n/k;
        }
        else{
            curr+=n/k+1;
        }
        cout<<curr << endl;
    }
    return 0;
}