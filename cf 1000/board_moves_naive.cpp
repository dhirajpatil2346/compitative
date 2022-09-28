#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int r= N/2,c=N/2;
    unsigned long long k = 0;
    for(int i=0;i<N;i++)
    {
        for(int j = 0 ; j < N ;j++)
        {
            k+=max(abs(i-r),abs(j-c));
        }
    }
    cout<<k<<endl;
    return 0;
}