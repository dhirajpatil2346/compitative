#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    // stack<int> st;
    // for (int i = 0; i < n; i++)
    //     if (st.empty() || st.top() != v[i])
    //         st.push(v[i]);
    // vector<int> nv;
    // while (!st.empty())
    // {
    //     nv.push_back(st.top());
    //     st.pop();
    // }
    // reverse(nv.begin(), nv.end());
    vector<int> color(n);
    color[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
        {
            color[i] = color[i - 1];
            continue;
        }
        int next = (i + 1) % n;
        if (color[next] == 0)
        {
            if (v[i] == v[i - 1])
            {
                color[i] = color[i - 1];
                continue;
            }
            for (int j = 1; j <= 3; j++)
                if (color[i - 1] != j)
                {
                    color[i] = j;
                    break;
                }
        }
        else
        {
            set<int> cl;
            cl.insert(color[i - 1]);
            cl.insert(color[next]);
            sort(cl.begin(), cl.end());
            for (int j = 1; j <= 3; j++)
            {
                bool nt = true;
                for (auto val : cl)
                    if (val == j)
                        nt = false;
                if (nt)
                {
                    color[i] = j;
                    break;
                }
            }
        }
    }
    cout << *max_element(color.begin(), color.end()) << endl;
    for (auto &val : color)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}