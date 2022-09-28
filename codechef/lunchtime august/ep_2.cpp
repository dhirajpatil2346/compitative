#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int even = 2;
        for (int i = 0; i < n; i += 2)
        {
            v[i] = even;
            even += 2;
        }
        int odd = 1;
        for (int i = 1; i < n; i += 2)
        {
            v[i] = odd;
            odd += 2;
        }
        for (auto &val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}