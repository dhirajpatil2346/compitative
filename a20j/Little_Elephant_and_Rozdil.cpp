#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],s[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
        s[i]=x;
    }
    sort(s,s+n);
    if(s[0]!=s[1] || n==1)
    {
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==s[0])
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }
    else{
        cout<<"Still Rozdil"<<endl;
    }
    return 0;
}