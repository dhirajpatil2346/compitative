#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    stack<char> st;
    string s;
    cin >> s;
    int i = 0;
    while (i < n)
    {
        if (st.size() % 2 == 0)
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() != s[i])
            {
                st.push(s[i]);
            }
        }
        i++;
    }
    if (st.size() % 2 == 1)
    {
        st.pop();
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << n - ans.length() << endl;
    cout << ans << endl;
    return 0;
}