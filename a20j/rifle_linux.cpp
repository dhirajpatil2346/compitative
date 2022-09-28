#include <bits/stdc++.h>
using namespace std;

void alter(long long arr[], long long n)
{
    long long a[n];
    for (long long i = 0; i < n; i++)
    {
        a[i] = arr[i];
    }

    for (long long i = 1, j = 2; j < n - 1;)
    {
        a[i] = arr[j];
        i++;
        j++, j++;
    }

    for (long long i = n / 2, j = 1; j < n - 1;)
    {
        a[i] = arr[j];
        i++;
        j++, j++;
    }

    for (long long i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long N;
        long long K;
        cin >> N >> K;
        long long arr[N];
        for (long long i = 0; i < N; i++)
        {
            arr[i] = i + 1;
        }
        long long q = K % (N - 2);
        if (q > 0)
        {
            for (long long i = 0; i < q; i++)
            {
                alter(arr, N);
            }
        }
        // cout << q << endl;
        for (long long i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}