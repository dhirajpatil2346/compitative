#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1;; i++)
    {
        n--;
        if (i % m == 0)
            n++;
        if (n == 0)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}