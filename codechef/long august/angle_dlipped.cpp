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
        int a[n][m], b[n][m];
        map<pair<int, int>, int> mp;
        map<pair<int, int>, int> sp;
        map<int, int> el1;
        map<int, int> el2;
        if (n == 1 || m == 1)
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cin >> a[i][j];
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cin >> b[i][j];
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] != b[i][j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag == 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int k = 0;
                for (int j = 0; j < m; j++)
                {
                    cin >> a[i][j];
                    if (i % 2 == 0)
                    {
                        if (j % 2 == 0)
                        {
                            pair<int, int> p{i, j};
                            mp.insert({p, 0});
                            el1.insert({a[i][j], 0});
                        }
                        else
                        {
                            pair<int, int> p{i, j};
                            sp.insert({p, 0});
                            el2.insert({a[i][j], 0});
                        }
                    }
                    if (i % 2 != 0)
                    {
                        if (j % 2 != 0)
                        {
                            pair<int, int> p{i, j};
                            mp.insert({p, 0});
                            el1.insert({a[i][j], 0});
                        }
                        else
                        {
                            pair<int, int> p{i, j};
                            sp.insert({p, 0});
                            el2.insert({a[i][j], 0});
                        }
                    }
                }
            }
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                int k = 0;
                for (int j = 0; j < m; j++)
                {
                    cin >> b[i][j];
                    if (i % 2 == 0)
                    {
                        if (j % 2 == 0)
                        {
                            if (el1.find(b[i][j]) == el1.end())
                            {
                                flag = 1;
                            }
                        }
                        else
                        {
                            if (el2.find(b[i][j]) == el2.end())
                            {
                                flag = 1;
                            }
                        }
                    }
                    if (i % 2 != 0)
                    {
                        if (j % 2 != 0)
                        {
                            if (el1.find(b[i][j]) == el1.end())
                            {
                                flag = 1;
                            }
                        }
                        else
                        {
                            if (el2.find(b[i][j]) == el2.end())
                            {
                                flag = 1;
                            }
                        }
                    }
                }
            }
            if (flag == 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}