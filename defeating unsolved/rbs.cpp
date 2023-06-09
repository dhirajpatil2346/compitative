#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
            if (st.empty())
                st.push('(');
            else
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        else
        {
            if (s[i] == ')')
                if (st.empty())
                    return false;
                else if (st.top() == '(')
                    st.pop();
                else
                    return false;
            else
                st.push(s[i]);
        }
    }
    return st.empty();
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}