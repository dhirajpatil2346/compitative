/*

*/
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << k << endl;
        }
        else
        {
            long long sum = (n * (n + 1)) / 2;
            long long N = n;
            sum++;
            if (k == sum)
            {
                for (int i = N; i >= 1; i--)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            else if (k < sum)
            {
                cout << -1 << endl;
            }
            else
            {
                n--;
                long long sum = (n * (n + 1)) / 2;
                sum++;
                if ((k - sum) % 2)
                {
                    cout << "-1" << endl;
                }
                else
                {
                    long long ele = (k - sum) / 2;
                    for (int i = n; i > 0; i--)
                    {
                        cout << i << " ";
                    }
                    cout << ele << endl;
                }
            }
        }
    }
    return 0;
}
