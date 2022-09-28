#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> z, o;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2)
        {
            o.push_back(i + 1);
        }
        else
        {
            z.push_back(i + 1);
        }
    }
    if (z.size() == 1)
    {
        cout << z[0] << endl;
    }
    else
    {
        cout << o[0] << endl;
    }
    return 0;
}