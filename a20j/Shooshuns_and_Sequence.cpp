#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = k-1; i < n; i++)
    {
        s.insert(arr[i]);
    }
    if(s.size()>1)
    {
        cout<<-1<<endl;
    }
    else
    {
        int count=0;
        int key=arr[k];
    }
    return 0;
}