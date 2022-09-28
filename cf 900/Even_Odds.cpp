#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int m, n;
    cin >> m >> n;
    if (m % 2 == 0)
    {
        if (n <= m / 2)
        {
            cout << n * 2 - 1;
        }
        else
        {

            cout << (n - m / 2) * 2;
        }
    }
    else
    {
        if (n % 2 == 0)
        {
            if (n <= (m / 2 + 1))
            {
                cout << n * 2 - 1;
            }
            else
            {
                cout << ((n - m / 2) * 2 - 2);
            }
        }
        else
        {
            if (n <= m / 2 + 1)
            {
                cout << n * 2 - 1;
            }
            else
            {

                cout << (n - m / 2) * 2 - 2;
            }
        }
    }
    /*
    long int n, m, N;
    cin >> N >> m;
    if (N % 2 != 0)
    {
        n = N / 2 + 1;
    }
    else
    {
        n = N / 2;
    }
    int arr[N];
    for (long int i = 0,j=1; i < n; i++)
    {
        arr[i]=j;
        j+=2;
    }
    for (long int i = n,j=2; i < N; i++)
    {
        arr[i]=j;
        j+=2;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     cout<<arr[i]<<"     ";
    // }

    cout<<arr[m-1];
    */
    return 0;
}