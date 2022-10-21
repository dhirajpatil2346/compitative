#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pv(vector<int> &v)
{
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int op = -1;
        vector<int> v1(n);
        for (int i = 0; i < n; i++)
        {
            v1[i] = i + 1;
        }
        vector<int> v2 = v1;
        for (int i = 0; i < k; i++)
        {
            if (op != -1)
            {
                break;
            }
            vector<int> v3;
            for (int i = 0; i < n; i += 2)
            {
                v3.push_back(v2[i]);
            }
            for (int i = 1; i < n; i += 2)
            {
                v3.push_back(v2[i]);
            }
            if (v3 == v1)
            {
                op = i + 1;
                break;
            }
            else
            {
                v2 = v3;
            }
            cout << i + 1 << " --> ";
            pv(v2);
        }
        if (op == -1)
        {
            pv(v2);
        }
        else
        {
            int need = k % op;
            v2 = v1;
            for (int i = 0; i < need; i++)
            {
                vector<int> v3;
                for (int i = 0; i < n; i += 2)
                {
                    v3.push_back(v2[i]);
                }
                for (int i = 1; i < n; i += 2)
                {
                    v3.push_back(v2[i]);
                }
                if (v3 == v1)
                {
                    op = i + 1;
                    break;
                }
                else
                {
                    v2 = v3;
                }
            }
            pv(v2);
        }
    }
    return 0;
}