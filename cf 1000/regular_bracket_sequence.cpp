#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (st.top() == '?' && s[i] == '?')
                {
                    st.pop();
                }
                else if (st.top() == '?' && s[i] == ')')
                {
                    st.pop();
                }
                else if (st.top() == '(' && s[i] == ')')
                {
                    st.pop();
                }
                else if (st.top() == '(' && s[i] == '?')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        if (st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}