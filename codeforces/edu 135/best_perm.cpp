#include <bits/stdc++.h>
using namespace std;

void zero(int n)
{
    vector<int> v = {n - 2, n - 1, n - 5, n - 4, n - 3, n};
    vector<bool> vis(n + 1);
    for (auto &val : v)
    {
        vis[val] = true;
    }
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
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

void one(int n)
{
    vector<int> v = {n - 2, n - 3, n - 1, n};
    vector<bool> vis(n + 1);
    for (auto &val : v)
    {
        vis[val] = true;
    }
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
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}
void two(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
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
        else if (n == 3)
        {
            cout << "2 1 3" << endl;
        }
        else
        {
            if (n % 3 == 0)
            {
                zero(n);
            }
            else if (n % 3 == 1)
            {
                one(n);
            }
            else
            {
                two(n);
            }
        }
    }
    return 0;
}