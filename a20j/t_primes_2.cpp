#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    for (auto &val : v)
    {
        int p = 2;

        for (long long i = 2; i <= val / 2; i++)
        {
            if (val % i == 0)
            {
                p++;
            }
        }
        if (p == 3)
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