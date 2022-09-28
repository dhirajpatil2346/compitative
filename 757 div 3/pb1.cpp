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
        int tom=1;
        int sum = 0, choco = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if ((x >= l) && (x <= r))
            {
                v.push_back(x);
            }
        }
        sort(v.begin(),v.end());
        // cout<<i<<"  "<<choco<<"     "<<endl;
        for (int i = 0; i < v.size(); i++)
        {
            
                sum += v[i];
                if (sum > k)
                {
                    // choco--;
                    tom = 0;
                    cout << choco << endl;
                    break;
                }
                choco++;
                
            
           
        }
         if (tom != 0)
            {
                cout << choco << endl;
            }
    }
}