#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int init = 1,  p = 1;
    long long d = 0;
    for (int i = 0; i < m; i++)
    {
        // cout<<p<<" "<<arr[i]<<" ";
        if (arr[i] >= p)
        {
            d += arr[i] - p;
            p = arr[i];
        }
        else
        {
            d += (n - p) + arr[i];
            p = arr[i];
        }
    }
    cout << d<<endl;
    return 0;
}