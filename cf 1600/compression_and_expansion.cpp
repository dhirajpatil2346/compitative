#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    stack<pair<int, int>> st;
    vector<string> ans(n);
    ans[0] = "1";
    vector<int> lvl(n), v(n), par(n);
    cin >> v[0];
    st.push({0, 0});
    par[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        if (x == 1)
        {
            par[i] = st.top().second;
            if (par[i] == -1)
                ans[i] = to_string(v[i]);
            else
                ans[i] = ans[par[i]] + "." + to_string(v[i]); //
            lvl[i] = st.top().first + 1;                      //
            st.push({lvl[i], i});                             //
        }
        else
        {
            if ((x - v[st.top().second]) == 1)
            {
            }
            else
            {
                int cl = st.top().first;
                while (!st.empty())
                {
                    while (!st.empty() && (cl == st.top().first))
                        st.pop();
                    if ((!st.empty()) && ((x - v[st.top().second]) == 1))
                        break;
                    else if (!st.empty())
                        cl = st.top().first;
                }
            }
            par[i] = par[st.top().second];
            if (par[i] == -1)
                ans[i] = to_string(v[i]);
            else
                ans[i] = ans[par[i]] + "." + to_string(v[i]);
            lvl[i] = st.top().first;
            st.push({lvl[i], i});
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
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