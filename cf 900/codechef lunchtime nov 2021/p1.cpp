#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        {
            long double S, A, B, C, final;
            cin >> S >> A >> B >> C;
            final = S + (0.01 * S * C);
            // cout<<"Final is "<<final<<endl;
            if ((final > A) && (final < B))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}