#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        bool got = false;
        for (int i = -1000; i < 1001; i++)
        {
            if (got)
            {
                break;
            }
            for (int j = i; j < 1001; j++)
            {
                if (got)
                {
                    break;
                }
                for (int k = j; k < 1001; k++)
                {
                    if (got)
                    {
                        break;
                    }
                    if (y != j)
                    {
                        continue;
                    }
                    int sum = i + j + k;
                    if (sum % 3)
                    {
                        continue;
                    }
                    if (sum / 3 == x)
                    {
                        cout << i << " " << j << " " << k << endl;
                        got = true;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}