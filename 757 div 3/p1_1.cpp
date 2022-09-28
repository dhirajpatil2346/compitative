#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        int sum = 0, choco = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cout<<i<<"  "<<choco<<"     "<<endl;
            if ((x >= l) && (x <= r))
            {
                sum += x;
            }
            if (sum < k)
            {
                cout<<"adding"<<endl;
                choco++;
                // conti;
            }
            else if (sum == k)
            {
                choco++;
                cout<<choco<<endl;
                break;
            }
            else if (sum > k)
            {
                choco--;
                cout << choco << endl;
                break;
                // continue; 
            }
        }
        // cout<<choco<<endl;
    }
    return 0;
}