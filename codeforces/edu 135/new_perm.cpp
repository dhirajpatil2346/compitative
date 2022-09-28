#include <bits/stdc++.h>
using namespace std;

void zero(int n)
{
    if (n % 2 == 0)
    {
        vector<int> v = {n / 2 - 1, n / 2, n};
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
    else
    {
        //cout<<"start";
        vector<int> v = {n / 2 - 1, n / 2 + 1, n};
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
}

void one(int n)
{
    //cout<<"one ";
    vector<int> v = {1, 2, n - 4, n};
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
    //cout<<"oneend"<<endl;
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
        else if (n == 5)
        {
            cout << "1 2 3 4 5" << endl;
        }
        else if (n == 6)
        {
            cout << "4 5 1 2 3 6" << endl;
        }
        else if (n % 3 == 0)
        {
            zero(n);
        }
        else if (n % 3 == 1)
        {
            one(n);
        }
        else if (n % 3 == 2)
        {
            two(n);
        }
    }
    return 0;
}