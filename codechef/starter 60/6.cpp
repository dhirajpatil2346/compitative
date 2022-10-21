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
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        bool already = true;
        for (int i = 0; i < n / 2; i++)
        {
            // cout << i << endl;
            if (v[i] != v[n - i - 1])
            {
                already = false;
                break;
            }
        }
        if (already)
        {
            cout << 0 << endl;
        }
        else
        {
            bool valid = true;
            for (int i = 0; i < n / 2; i++)
            {
                // cout << i << endl;
                if (v[i] > v[n - i - 1])
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
            {
                cout << -1 << endl;
            }
            else
            {
                int steps = 0;
                bool fault = false;
                for (int i = n / 2 - 1; i >= 0; i--)
                {
                    cout << i << steps << v[i] << endl;
                    v[i] += steps;
                    if (v[i] == v[n - i - 1])
                    {
                        cout << "passed" << endl;
                        continue;
                    }
                    if (v[i] < v[n - i - 1])
                    {
                        int diff = v[n - i - 1] - v[i];
                        v[i] += diff;
                        steps += diff;
                    }
                    else
                    {
                        cout << "fyf" << i << endl;
                        fault = true;
                    }
                    cout << v[i] << endl;
                }
                if (fault)
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << steps << endl;
                }
            }
        }
    }
    return 0;
}