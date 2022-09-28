#include <bits/stdc++.h>
using namespace std;
bool got = true;
char arr[101][101];
void both_odd(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            got = true;
        }
        else
        {
            got = false;
        }
        for (int j = 0; j < m; j++)
        {

            if (got)
            {
                arr[i][j] = 'W';
                got = false;
            }
            else
            {
                arr[i][j] = 'B';
                got = true;
            }
        }
    }
}

void oe(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            got = true;
        }
        else
        {
            got = false;
        }
        for (int j = 0; j < m; j++)
        {

            if (got)
            {
                arr[i][j] = 'W';
                got = false;
            }
            else
            {
                arr[i][j] = 'B';
                got = true;
            }
        }
    }
    arr[n - 1][m - 1] = 'B';
}

void be(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            got = true;
        }
        else
        {
            got = false;
        }
        for (int j = 0; j < m; j++)
        {

            if (got)
            {
                arr[i][j] = 'W';
                got = false;
            }
            else
            {
                arr[i][j] = 'B';
                got = true;
            }
        }
    }
    arr[n - 1][0] = 'B';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n % 2 && m % 2)
        {
            both_odd(n, m);
        }
        else if ((n % 2 && (!(m % 2))) || ((!(n % 2)) && m % 2))
        {
            oe(n, m);
        }
        else
        {
            be(n, m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}