#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int height = 0;
    for (int i = 0, curr = 0; i < m; i++)
    {
        int x;
        cin>>x;
        if(x>n){
            curr+=2;
        }
        else{
            curr++;
        }
        height = curr;
    }
    cout<<height;
    return 0;
}