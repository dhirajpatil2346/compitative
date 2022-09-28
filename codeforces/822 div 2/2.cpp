#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
        {
            cout << 1 << "\n1 1" << endl;
        }
        else
        {
            cout << 1 << "\n1 1" << endl;
            for (int i = 3; i <= n; i++)
            {
                if (i % 2 == 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if(j%2)
                        {
                            cout<<1<<" ";
                        }
                        else
                        {
                            cout<<"0 ";
                        }
                    }
                    cout << endl;
                }
                else
                {
                    for (int j = 1; j <= i; j++)
                    {
                        cout << j % 2 << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}