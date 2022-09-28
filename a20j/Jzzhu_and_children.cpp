#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n>>m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > m)
        {
            // cout<<i+1<<endl;
            if (x % m == 0)
            {
                arr[i] = x / m;
            }
            else
            {
                arr[i] = x / m + 1;
            }
        }
        else
        {
            arr[i] = 0;
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[p] <= arr[i])
        {
            p = i;
        }
    }
    cout << p + 1 << endl;

    return 0;
}