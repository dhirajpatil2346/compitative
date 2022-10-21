#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 3 || n == 1)
        {
            cout << -1 << endl;
        }
        else if (n == 5)
        {
            cout << "5 4 1 2 3" << endl;
        }
        else
        {
            vector<int> v(n);
            int even = 2, odd = 1;
            if (n % 2 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (i % 2)
                    {
                        v[i] = odd;
                        odd += 2;
                    }
                    else
                    {

                        v[i] = even;
                        even += 2;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
            }
            else
            {
                int mid = (1 + n) / 2;
                for (int i = n; i > mid + 1; i--)
                {
                    cout << i << " ";
                }
                cout << mid << " " << mid + 1 << " ";
                for (int i = mid - 1; i > 0; i--)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}