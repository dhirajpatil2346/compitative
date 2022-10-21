#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }
    int ele = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            ele = i;
            break;
        }
    }
    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i == ele)
        {
            continue;
        }
        cout << ele << " " << i << endl;
    }

    return 0;
}