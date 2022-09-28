#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int F = 0; F < T; F++)
    {
        /* code */

        int n;
        cin >> n;
        if (n > 4)
        {
            for (int q = n - 1, w = 1; q != 0; w++, q--)
            {
                // cout<<q<<"  "<<w<<endl;
                int k = q, l = w, D = q, e = w;
                vector<int> a, b, c, d;
                while (k != 0)
                {
                    a.push_back(k % 2);
                    k = k / 2;
                }
                for (auto it = a.rbegin(); it != a.rend(); it++)
                {
                    b.push_back(*it);
                }
                while (l != 0)
                {
                    c.push_back(l % 2);
                    l = l / 2;
                }
                for (auto itr = c.rbegin(); itr != c.rend(); itr++)
                {
                    d.push_back(*itr);
                }
                if ((a == b) && (c == d))
                {
                    cout<<2<<endl;
                    cout << D << " " << e << endl;
                    break;
                }
            }
        }
        else
        {
                cout<<n<<endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}