#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int h = 1;
        h += v[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i] == 0 && v[i - 1] == 0)
            {
                h = -1;
                break;
            }
            else if (v[i] == 1 && v[i - 1] == 1)
            {
                h += 5;
            }
            else
            {
                h += v[i];
            }
        }
        cout << h << endl;
    }
    return 0;
}