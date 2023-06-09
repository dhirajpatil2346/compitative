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
        if (st.empty() || s[i] == '?')
            st.push(s[i]);
        else if (st.top() == '(' && s[i] == ')')
            st.pop();
        else
            st.push(s[i]);
    }
    if (st.size() % 2)
        return false;
    string h = "";
    while (!st.empty())
    {
        h += st.top();
        st.pop();
    }
    reverse(h.begin(), h.end());
    s = h;
    // cout << s << endl;
    int oneeded = s.length() / 2 - count(s.begin(), s.end(), '('), cneeded = s.length() / 2 - count(s.begin(), s.end(), ')');
    if (oneeded < 0 || cneeded < 0)
        return false;
    int O = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        else
        {
            if (oneeded)
            {
                st.push('(');
                oneeded--;
            }
            else if (cneeded)
            {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
                cneeded--;
            }
            else
                return false;
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