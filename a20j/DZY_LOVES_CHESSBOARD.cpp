#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m], sol[n][m];
    for (int i = 0; i < n; i++)
    {
        int y;
        if (i % 2 == 0)
        {
            y = 0;
        }
        else
        {
            y = 1;
        }
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '-')
            {
                sol[i][j] = '-';
                y++;
            }
            else if (y % 2 == 1)
            {
                sol[i][j] = 'W';
                y++;
            }
            else
            {
                sol[i][j] = 'B';
                y++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << sol[i][j];
        }
        cout << endl;
    }

    return 0;
}