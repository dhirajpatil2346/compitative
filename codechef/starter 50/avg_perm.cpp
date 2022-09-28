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
        int start = n, pos = 0;
        while (start > 0)
        {
            v[pos] = start;
            start -= 2;
            pos++;
        }
        pos = n - 1, start = n - 1;
        while (start > 0)
        {
            v[pos] = start;
            start -= 2;
            pos--;
        }
        for (auto &val : v)
        {
            cout << val << endl;
        }
    }
    return 0;
}