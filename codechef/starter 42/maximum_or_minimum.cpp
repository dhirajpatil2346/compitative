#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n), v3(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        v2 = v1, v3 = v1;
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end(), cmp);
        if (v1 == v2 || v1 == v3)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}