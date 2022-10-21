#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int t = n * (n + 1) / 2;
    m %= t;
    int curr = m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (curr < i)
        {
            ans = curr;
            break;
        }
        curr -= i;
    }
    cout << ans << endl;
    return 0;
}