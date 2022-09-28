#include<bits/stdc++.h>
using namespace std;

int main(){
    int curr=1,n=1;
    while(curr<=1000000000)
    {
        curr*=3;
        n++;
    }
    cout<<curr<<"  "<<n<<endl;
    return 0;
}