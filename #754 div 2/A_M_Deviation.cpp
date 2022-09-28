#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> st;
        st.push_back(x);
        st.push_back(y);
        st.push_back(z);
        sort(st.begin(), st.end());
        cout<<"start"<<endl;
        for (auto v : st)
        {
            cout << v << endl;
        }
        cout << "end" << endl;
        auto yt = st.begin();
        auto first = yt;
        yt++;
        auto second = yt;
        yt++;
        auto third = yt;
        int m = *first, n = *second, o = *third;
        int j = 0;
        cout << "m is     " << m << endl;
        cout << "n is     " << n << endl;
        cout << "o is     " << o << endl;

        int min;
        cout << "m + o      " << m + o << endl;
        cout << "2 * n is   " << 2 * n << endl;
        min = (m + o) - 2 * (n);
        cout << "min once is " << min << endl;
        // cout << (*first+1) + (*second-1) << endl;
        // cout << *third << endl;
        if ((m + n) >= o)
        {
            // cout << "first one " << endl;
            while (true)
            {
                // cout << "test no. " << j + 1 << endl;
                // cout << 1 << "  " << *first + *third << endl;
                // cout << 2 << "  " << *second << endl;
                // cout << j << endl;
                // cout << "min is   " << min << endl;
                int k = (m + o) - 2 * (n);
                cout<<"k is     "<<endl;
                if (min == 0)
                {
                    cout << j << endl;
                    break;
                }
                else if (k > min)
                {
                    cout << j << endl;
                    break;
                }
                else
                {
                    m++;
                    n--;
                    j++;
                }
                if (min > k)
                {
                    min = k;
                }
                else
                {
                }
                // delay(100000);
            }
        }
        else
        {
            while (true)
            {
                int k = (m + o) - 2 * (n);
                cout<<"k is     "<<k<<endl;
                // cout << "test no. " << j + 1 << endl;
                // cout << 1 << "  " << *first + *third << endl;
                // cout << 2 << "  " << *second << endl;
                // cout << j << endl;
                if (min == 0)
                {
                    cout << j << endl;
                    break;
                }
                else if (k > min)
                {
                    cout << j << endl;
                    break;
                }
                else
                {
                    m--;
                    n++;
                    j++;
                }
                if (min > k)
                {
                    min = k;
                }
                else
                {
                }
            }
        }
    }

    return 0;
}