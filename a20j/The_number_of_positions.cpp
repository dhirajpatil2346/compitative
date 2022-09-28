#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    /*
    cout<<n-a;
    */
    cin >> n >> a >> b;
   int output=0;
        int pos=a+1;
//    cout<<pos<<endl;
        for(int i=pos;i<=n;i++)
        {
                // cout<<n<<" "<<i<<" "<<pos<<" "<<output<<endl;                
            if(n-i<=b){
                output++;
            }
        }
    cout<<output;
    return 0;
}