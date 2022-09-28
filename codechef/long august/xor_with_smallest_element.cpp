#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            s.insert(c);
        }
        while (y > 0)
        {
            auto curr = s.begin();

            if ((*curr ^ x) > *curr)
            {
                s.erase(curr);
                s.insert(*curr ^ x);
                y--;
            }
            else
            {
                if ((y & 1) == 0)
                {
                    break;
                }
                else
                {
                    s.erase(curr);
                    s.insert(*curr ^ x);
                    break;
                }
            }
        }
        for (auto &val : s)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}