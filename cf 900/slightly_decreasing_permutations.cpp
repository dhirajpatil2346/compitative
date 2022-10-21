#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int l = n - k;
    for (int i = 0; i < k; i++)
    {
        cout << n-- << " ";
    }
    for (int i = 1; i <= l; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}