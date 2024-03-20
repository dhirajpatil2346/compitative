#include <bits/stdc++.h>
using namespace std;
long long f(long long n)
{
    if (n == 2 || n == 1)
        return 1;
    return f(n - f(n - 1)) + f(n - f(n - 2));
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    arr[2] = 1, arr[1] = 1;
    for (int i = 3; i < n + 1; i++)
        arr[i] = arr[i - arr[i - 1]] + arr[i - arr[i - 2]];
    for (int i = 1; i < n + 1; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}