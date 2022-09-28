#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n], p[m];
        for (auto &val : arr)
        {
            cin >> val;
        }
        for (auto &val : p)
        {
            cin >> val;
        }
        int arr2[n];
        for (int i = 0; i < n; i++)
        {
            arr2[i] = arr[i];
        }
        sort(arr2, arr2 + n);
        sort(p, p + m);
        for (int i = 0; i < m; i++)
        {
            // cout << i << endl;
            int start = p[i] - 1;
            int j = i;
            for (j = i; j < m - 1; j++)
            {
                if (p[j + 1] - p[j] > 1)
                {
                    break;
                }
            }
            int end = p[j]+1;
            // cout << start << "  " << end << endl;
            sort(arr + start, arr + end);
        }

        for (auto &val : arr)
        {
            // cout << val << " ";
        }
        // cout << endl;

        bool got = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr2[i])
            {
                got = true;
            }
        }
        if (got)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}