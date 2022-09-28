#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    int num1 = 0;
    for (int i = 0; i < n; i++)
    {
        int r = 0, l = 0, u = 0, b = 0;
        for (int j = 0; j < n; j++)
        {
            if(j!=i)
            {
                if(arr[i][0]>arr[j][0] && arr[i][1]==arr[j][1])
                {
                    r=1;
                }
                else if(arr[i][0]<arr[j][0] && arr[i][1]==arr[j][1])
                {
                    l=1;
                }
                else if(arr[i][0]==arr[j][0] && arr[i][1]<arr[j][1])
                {
                    b=1;
                }
                else if(arr[i][0]==arr[j][0] && arr[i][1]>arr[j][1])
                {
                    u=1;
                }
            }
        }
        if(l==1 && r==1 && u==1 && b==1)
        {
            num1++;
        }
        // cout<<i<<endl;
    }
    cout<<num1;
    return 0;
}