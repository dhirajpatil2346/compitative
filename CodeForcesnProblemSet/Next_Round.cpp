#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout<<"The first element is "<<arr[0]<<endl;
    if(arr[0] <= 0){
        // cout<<"LOOP 1 "<<endl;
        cout<<0;
    }
    else if(arr[m-1] == 0){
        // cout<<"loop 2"<<endl;
        int y=arr[m-1];
        // cout<<"y is "<<y<<endl;
        int k =m-1;
        // cout<<"arr first test is    "<<arr[m-1]<<endl;
        // for (int i = m-1; y==arr[i]; i++)
        for(int i = m-1; y==arr[i]; i--)
        {
            // cout<<"This is time "<<endl;
            k--;
            // cout<<"Now k is "<<k<<endl;
        }
        cout<<k+1;
    }
    else{
        // cout<<"loop 2 "<<endl;
        int y=arr[m-1];
        // cout<<"y is "<<y<<endl;
        int k =m-1;
        for (int i = m-1; arr[i] == y; i++)
        {
            // cout<<"This is time "<<endl;
            k++;
            // cout<<"Now k is "<<k<<endl;
        }
        cout<<k;
    }
    return 0;
}