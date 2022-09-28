#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 3)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> odd, even;
            for (int i = 1; i <= n; i++)
            {
                if (i % 2)
                {
                    odd.push_back(i);
                }
                else
                {
                    even.push_back(i);
                }
            }
            for (auto &val : even)
            {
                cout << val << " ";
            }
            for (auto &val : odd)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}