#include <bits/stdc++.h>
using namespace std;

void odd(int n)
{
    // n %3 ==0
    if (n % 3 == 0)
    {
        vector<int> end = {n - 1, n};
        vector<bool> vis(n + 1);
        vis[1] = false, vis[n - 1] = true, vis[n] = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            else
            {
                cout << i << " ";
            }
        }
        for (auto &val : end)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int> end = {1, n - 1, n};
        vector<bool> vis(n + 1);
        vis[1] = true, vis[n - 1] = true, vis[n] = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            else
            {
                cout << i << " ";
            }
        }
        for (auto &val : end)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void even(int n)
{
    // n % 3 == 1
    if (n % 3 == 1)
    {
        vector<int> end = {n / 2 - 1, n / 2, n};
        vector<bool> vis(n + 1);
        vis[1] = false, vis[n / 2 - 1] = true, vis[n / 2] = true, vis[n] = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            else
            {
                cout << i << " ";
            }
        }
        for (auto &val : end)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int> end = {1, n / 2 - 1, n / 2, n};
        vector<bool> vis(n + 1);
        vis[1] = true, vis[n / 2 - 1] = true, vis[n / 2] = true, vis[n] = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            else
            {
                cout << i << " ";
            }
        }
        for (auto &val : end)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
        {
            cout << "1 2" << endl;
        }
        else if (n == 3)
        {
            cout << "2 1 3" << endl;
        }
        else if (n == 4)
        {
            cout << "2 1 3 4" << endl;
        }
        else
        {
            if (n % 2)
            {
                odd(n);
            }
            else
            {
                even(n);
            }
        }
    }
    return 0;
}