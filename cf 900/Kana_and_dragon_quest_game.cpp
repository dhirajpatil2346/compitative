#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int h, n, m;
        cin >> h >> n >> m;
        for (int i = 0; i < n; i++)
        {
            if((h<20)){
                break;
            }
            h = h / 2 + 10;
        }
        for (int i = 0; i < m; i++)
        {
            h = h - 10;
        }
        // cout<<h<<"  ";
        if (h <= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}