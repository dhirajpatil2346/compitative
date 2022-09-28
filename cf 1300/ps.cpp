#include <bits/stdc++.h>
using namespace std;
#define ll long long

int productOfSums(int arr[], int n)
{
    int p = 0;
    int i = 1;
    while (i < n)
    {
        if (arr[i - 1] <= arr[i])
        {
            p++;
            i++;
        }
        else
        {
            break;
        }
    }
    p = i;
    cout << p << endl;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < p; i++)
    {
        s1 += arr[i];
    }
    for (int i = p-1; i < n; i++)
    {
        s2 += arr[i];
    }

    return s1 * s2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {3,8,14,12,10,7,4};
    int n = 7;
    cout << productOfSums(arr, n);
    return 0;
}