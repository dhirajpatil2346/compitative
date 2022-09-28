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
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        int front = 0;
        int mini = v[front++];
        for (int i = 0; i < n - 1; i++)
        {
            int key = v[i];
            for (int j = i; j < n; j++)
            {
                v[j] -= key;
            }
            mini = max(v[front++], mini);
        }
        cout << mini << endl;
    }
    return 0;
}