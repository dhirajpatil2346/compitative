#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int g(int a, int b)
{
    if (b == 0)
        return a;
    return g(b, a % b);
}

int *generalizedGCD(int *arr, int len)
{
    int n = len / 2 + len % 2;
    int* arrp;
    arrp=new int[n];
    int i = 0, j = 0;

    for (i = 0, j = 0; i < len; i += 2, j++)
        arrp[j] = arr[i];
    // free(arr);
    // arr = new int[n];
    // for (int u = 0; u < n; u++)
    //     arr[u] = arrp[u];
    return arrp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr = generalizedGCD(arr, n);
    for (int i = 0; i < n / 2; i++)
        cout << arr[i];
    return 0;
}