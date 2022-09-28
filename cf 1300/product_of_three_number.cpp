#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unordered_set<int> us;
        int n;
        cin >> n;
        int c = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                // cout << n << "    " << i << endl;
                us.insert(i);
                c++;
                n /= i;
            }
            if (c == 2)
            {
                break;
            }
        }
        // cout << n << endl;
        if (n >= 2)
        {
            us.insert(n);
        }
        if (us.size() == 3)
        {
            cout << "YES" << endl;
            for (auto &val : us)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}