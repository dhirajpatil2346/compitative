#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    /*
    00 11
    00 21
    10 21
    01 10
    01 20
    11 20
    */
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            if(i==j){
                continue;
            }
            else if (arr[i][0] == arr[j][1])
            {
                // cout<<i+1<<"  "<<j+1<<" "<<count<<endl;
                count++;
            }
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                continue;
            }
            else if(arr[i][1] == arr[j][0])
            {
                cout<<i+1<<"  "<<j+1<<" "<<count<<endl;
                count++;
            }
        }
        
    }
    */
    cout<<count;
    return 0;
}