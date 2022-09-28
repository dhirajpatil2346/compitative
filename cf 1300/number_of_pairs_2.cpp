#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bin(int arr[], int l, int r, int n)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (n == arr[mid])
        {
            return mid;
        }
        else if (n < arr[mid])
        {
            return bin(arr, l, mid - 1, n);
        }
        else
        {
            return bin(arr, mid + 1, r, n);
        }
    }
    return -1;
}

int binr(int arr[], int l, int r, int n)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        cout << l + 1 << " " << r + 1 << endl;
        if (n == arr[mid])
        {
            return mid;
        }
        if (l == r)
        {
            if (arr[l] <= n)
            {
                return l;
            }
            else
            {
                return -1;
            }
        }
        else if(r-l==1)
        {
            
        }
        else if (n <= arr[mid])
        {
            return binr(arr, l, mid, n);
        }
        else
        {
            return binr(arr, mid, r, n);
        }
    }
    return -1;
}

int binl(int arr[], int l, int r, int n)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        if (n == arr[mid])
        {
            return mid;
        }
        if (l == r)
        {
            if (arr[l] >= n)
            {
                return l;
            }
            else
            {
                return -1;
            }
        }
        else if (n <= arr[mid])
        {
            return binl(arr, l, mid, n);
        }
        else
        {
            return binl(arr, mid + 1, r, n);
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << binr(arr, 0, n - 1, 4) << endl;
    return 0;
}