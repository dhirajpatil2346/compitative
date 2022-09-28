#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a0[n][n] = {'0'};
    char a90[n][n] = {'0'};
    char a180[n][n] = {'0'};
    char a270[n][n] = {'0'};
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        for (int j = 0; j < n; j++)
        {
            a0[i][j] = s[j];
        }
    }
    int mod = 0;
    /*
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a0[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    */
    // creating 90 degree
    int col=n-1;
     col = n - 1;
    for (int i = 0; i < n; i++)
    {
        string k = v[i];
        for (int j = 0; j < n; j++)
        {
            a0[j][col] = k[j];
        }
        col--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a90[i][j] != a0[i][j])
            {
                mod++;
                a0[i][j] = a90[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            s += a0[i][j];
        }
        v[i] = s;
    }
    /*
for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a90[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
*/
    // creating 180
     col = n - 1;
    for (int i = 0; i < n; i++)
    {
        string k = v[i];
        for (int j = 0; j < n; j++)
        {
            a0[j][col] = k[j];
        }
        col--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a180[i][j] != a0[i][j])
            {
                mod++;
                a0[i][j] = a180[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            s += a0[i][j];
        }
        v[i] = s;
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a180[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    */
    // creating 270
     col = n - 1;
    for (int i = 0; i < n; i++)
    {
        string k = v[i];
        for (int j = 0; j < n; j++)
        {
            a0[j][col] = k[j];
        }
        col--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a270[i][j] != a0[i][j])
            {
                mod++;
                a0[i][j] = a270[i][j];
            }
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a270[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    */
    cout<<mod<<endl;
    return 0;
}