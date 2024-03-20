#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<int> v(1e6 + 1, 1);
    for (int i = 2; i <= 1e6; i++)
        if (v[i] == 1)
        {
            for (int k = 1; k <= i && ((i + i * k) <= 1e6); k++)
              {  v[i + i * k] = 0;}
        }
    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
    while (t--)
    {
        int x;
        cin >> x;
        cout << v[x] << endl;
    }
    return 0;
}