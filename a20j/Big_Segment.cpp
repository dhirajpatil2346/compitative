#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int mini = INT_MAX, maxi = INT_MIN;
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        mini=min(mini, arr[i][0]), maxi = max(maxi, arr[i][1]);
    }
    bool got=true;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if(mini == arr[i][0] && maxi==arr[i][1])
        {
            got=false;
            m=i;
            break;
        }
    }
    if(got)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<m+1<<endl;
    }
    return 0;
}