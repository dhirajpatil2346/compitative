#include <bits/stdc++.h>
using namespace std;
unsigned long long req(int n)
{
    if (n == 1)
    {
        return 0;
    }
    return (((2 * n + 2 * (n - 2)) * (n / 2)) + req(n - 2));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int d=1;
        unsigned long long k = 0;
        int col = 3;
        for (int i = 1; i <= n/2; i++)
        {
            unsigned long long curr =d*1ll*(col*2+(col-2)*2);
            k+=curr;
            col+=2;
            d++;
        }
        cout << k << endl;
    }
    return 0;
}