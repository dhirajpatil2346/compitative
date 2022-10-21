#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        for (auto &val : v1)
        {
            cin >> val;
        }
        for (auto &val : v2)
        {
            cin >> val;
        }
        vector<int> c1(n), c2(n);
        c1[0] = v1[0], c2[n - 1] = v2[n - 1];
        for (int i = 1; i < n; i++)
        {
            c1[i] = v1[i] + c1[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            c2[i] = v2[i] + c2[i + 1];
        }
        /*
        for (auto &val : c1)
        {
            cout << val << " ";
        }
        cout << endl;
        for (auto &val : c2)
        {
            cout << val << " ";
        }
        cout << endl;
        */
        int minc = max(c1[n - 1] - c1[0], c2[0] - c2[0]);
        for (int i = 1; i < n; i++)
        {
            int right = c1[n - 1] - c1[i];
            int left = c2[0] - c2[i];
            minc = min(minc, max(left, right));
        }
        cout << minc << endl;
    }
    return 0;
}