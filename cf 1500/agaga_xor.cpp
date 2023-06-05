#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (auto &val : v)
            cin >> val;
        long long a = 0;
        for (auto &val : v)
            a ^= val;
        vector<long long> forw = v, back = v;
        stack<long long> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || st.top() == v[i])
            {
                st.push(v[i]);
                continue;
            }
            else
            {
                long long c = v[i];
                while (!st.empty())
                {
                    long long tp = st.top();
                    st.pop();
                    if (st.empty() || tp ^ c == st.top())
                    {
                        st.push(tp ^ c);
                        break;
                    }
                    else
                    {
                        c = tp ^ c;
                    }
                }
            }
        }
        // stack<int> g = st;
        // while (!st.empty())
        // {
        //     cout << st.top() << " ";
        //     st.pop();
        // }
        // cout << endl;
        if (st.size() == 1)
            cout << "NO" << endl;
        else
        {
            set<long long> s;
            while (!st.empty())
            {

                s.insert(st.top());
                st.pop();
            }
            if (s.size() != 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}