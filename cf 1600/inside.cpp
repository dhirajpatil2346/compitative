#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (auto &val : v)
            cin >> val;
        long long sum = 0;
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += v[i - 1];
            if (sum % i)
                continue;
            else if (sum == i)
                c++;
        }
        cout << c << endl;
    }
    return 0;
}
