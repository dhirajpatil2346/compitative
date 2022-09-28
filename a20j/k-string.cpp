#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> m;
    set<char> st;
    int t=0;
    for (int i = 0; i < s.length(); i++)
    {
        st.insert(s[i]);
        if (m.count(s[i]) == 0)
        {

            m[s[i]] = 1;
            t++;
        }
        else
        {
            m[s[i]]++;
        }
    }
    bool get = true;
    int c = m.begin()->second;
    // cout << c << "  " << n << endl;
    if ((s.length() / st.size()) == n)
    {
        // cout << "run" << endl;
        for (auto &it : m)
        {
            if (it.second != c)
            {
                get = false;
                break;
            }
        }
    }
    else
    {
        cout << -1<<endl;
        return 0;
    }
    // else
    // {
    // cout<<t<<endl;
    if (get)
    {
        for (int i = 0; i<s.length()/t; i++)
        {
            for (auto &it : m)
            {
                cout << it.first;
            }
        }
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}