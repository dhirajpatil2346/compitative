#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            pos = i;
            break;
        }
    }
    int zero = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            zero = i;
            break;
        }
    }
    int neg = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            neg = i;
            break;
        }
    }
    if (pos >= 0 && neg >= 0)
    {
        cout << 1 << " " << v[neg] << endl;
        cout << 1 << " " << v[pos] << endl;
        cout << n - 2 << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == pos || i == neg)
            {
                continue;
            }
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else
    {
        int neg2 = -1;
        int neg3 = -1;
        for (int i = neg + 1; i < n; i++)
        {
            if (v[i] < 0)
            {
                neg2 = i;
                break;
            }
        }
        for (int i = neg2 + 1; i < n; i++)
        {
            if (v[i] < 0)
            {
                neg3 = i;
                break;
            }
        }
        cout << 1 << " " << v[neg] << endl;
        cout << 2 << " " << v[neg2] << " " << v[neg3] << endl;
        cout << n - 3 << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == neg2 || i == neg3 || i == neg)
            {
                continue;
            }
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}