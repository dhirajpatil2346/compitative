#include<numeric>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unordered_set<pair<int,int>> us;
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                int a = __gcd(i,j);
                int b = lcm (i,j);
                if(a/b<=3)
                {

                }
            }
            
        }
        
    }
    return 0;
}