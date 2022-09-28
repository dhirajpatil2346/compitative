#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cin >> m;
        vector<int> v1(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v1[i];
        }
        int max1 = *(max_element(v.begin(), v.end())), max2 = *(max_element(v1.begin(), v1.end()));
        if (max1 > max2)
        {
            cout << "Alice\nAlice" << endl;
        }
        else if (max1 < max2)
        {
            cout << "Bob\nBob" << endl;
        }
        else if (max1 == max2)
        {
            cout << "Alice\nBob" << endl;
        }
    }
    return 0;
}