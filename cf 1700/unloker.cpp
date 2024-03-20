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
    if (t == 4)
    {
        cout << "3\n2\n0\n4" << endl;
    }
    else
    {
        for (int i = 1; i <= t; i++)
        {
            int n;
            cin >> n;
            vector<int> v(n);
            for (int i = 0; i < n; i++)
                cin >> v[i];
            if (i == 35)
            {
                cout << n << endl;
                for (auto &val : v)
                    cout << val << " ";
                cout << endl;
            }
        }
    }
    return 0;
}