#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int arr[7][2];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = 1;
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < 2; i++)
    {
        int n;
        cin >> n;
        if (n % 2)
        {
            int j = n / 2;
            arr[j][0] = 0;
        }
        else
        {
            int j = n / 2 - 1;
            arr[j][1] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= k/2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (arr[i][j] == 0)
            {
                continue;
            }
            else
            {
                // if ((i - 1) >= 0 && (i - 1) <= k/2)
                // {
                //     if (arr[i - 1][j] == 1)
                //     {
                //         cnt++;
                //     }
                // }
                if ((i + 1) >= 0 && (i + 1) <= k/2)
                {
                    if (arr[i + 1][j] == 1)
                    {
                        cnt++;
                    }
                }
                // if ((j - 1) >= 0 && (j - 1) <= 1)
                // {
                //     if (arr[i][j - 1] == 1)
                //     {
                //         cnt++;
                //     }
                // }
                if ((j + 1) >= 0 && (j + 1) <= 1)
                {
                    if (arr[i][j - 1] == 1)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}