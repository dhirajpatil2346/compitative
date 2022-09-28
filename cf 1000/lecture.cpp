#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<string, string> m;
    for (int i = 0; i < k; i++)
    {
        string a, b;
        cin >> a >> b;
        if (a.length() < b.length() || a.length() == b.length())
        {
            m[a] = a;
            m[b] = a;
        }
        else
        {
            m[a] = b;
            m[b] = b;
        }
    }

    string s;

    getline(cin >> ws, s);
    // cout << s << endl;
    int ws = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ws++;
        }
    }
    // cout<<ws<<endl;
    vector<string> v(ws + 1);
    for (int i = 0, j = 0; i < ws, j < s.length(); j++, i++)
    {
        v[i] = "";
        while (j < s.length() && s[j] != ' ')
        {
            v[i] += s[j];
            j++;
        }
    }
    /*
    for(auto &val:v)
    {
        cout<<val<<endl;
    }
    cout<<endl;
    */
    for (auto &val : v)
    {
        cout << m[val] << " ";
    }
    cout<<endl;
    return 0;
}