#include <iostream>
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
        int arr[n + 1];
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] < i)
            {
                continue;
            }
            int key = arr[i] - i;
            for (int j = key; j <= n; j += arr[i])
            {
                if ((i == j) || (j == 0))
                {
                    continue;
                }
                ll k = arr[i] * 1ll * arr[j];
                if (k == (i + j))
                {
                    c++;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}