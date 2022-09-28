#include <bits/stdc++.h>
using namespace std;
const long long m = 1073741824;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int total = a * b * c + 1;
    vector<int> v(total, 2);
    v[1] = 1;
    for (int i = 2; i < total; i++)
    {
        for (int j = 2 * i; j < total; j += i)
        {
            v[j]++;
        }
    }
    /*
    for (int i = 1; i < total; i++)
    {
        cout << i << "  " << v[i] << endl;
    }
*/
    long long ans = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                int z = i * j * k;
                // cout << z << "  " << v[z] << endl;
                ans += v[z];
                ans %= m;
            }
        }
    }
    cout << ans << endl;
    return 0;
}