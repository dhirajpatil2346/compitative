#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int k = n - i;
        for (int x = 0; x < k; x++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (j == i)
                cout << j;
            else
                cout << j << " ";
        }
        for (int m = i - 1; m >= 0; m--)
        {
            // if(m==0)
            //     cout<<m;
            // else
            cout << " " << m;
        }
        // for (int x = k - 1; x >= 0; x--)
        // {
        //     cout << "  ";
        // }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int k = n - i;
        for (int x = 0; x < k; x++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (j == i)
                cout << j;
            else
                cout << j << " ";
        }
        for (int m = i - 1; m >= 0; m--)
        {
            // if(m==0)
            //     cout<<m;
            // else
            cout << " " << m;
        }
        // for (int x = k - 1; x >= 0; x--)
        // {
        //     cout << "  ";
        // }
        cout << endl;
    }
    return 0;
}