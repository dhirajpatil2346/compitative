#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (k < n)
    {
        cout << -1 << endl;
    }
    else if (k == n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        int p = k - n;
        int ones = n - p;
        cout << p << "  " << ones << endl;
        // position of 1 will be ones from last
        // position of 2 will be p back to ones
        vector<int> v(n);
        int curr = 2;
        int i = 0;
        int j = p;
        while (j--)
        {
            v[i] = curr;
            curr += 2;
            i+=2;;
        }
        v[p] = 1;
        j = p, curr = 3, i = 1;
        while (j--)
        {
            v[i] = curr;
            curr += 2;
            i+=2;
        }
        for (int l = k; l < n; l++)
        {
            v[l] = l + 1;
        }
        for (auto &val : v)
        {
            cout << val << endl;
        }
    }
    return 0;
}