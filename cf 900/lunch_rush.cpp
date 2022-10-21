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
    int sc = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > k)
        {
            sc = max(sc, x - (y - k));
        }
        else
        {
            sc = max(sc, x);
        }
    }
    cout << sc << endl;
    return 0;
}