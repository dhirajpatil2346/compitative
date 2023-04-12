#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int i = 0;
    int n = s.length();
    vector<string> v;
    while (i < n)
    {
        if (s[i] == '/')
        {
            i++;
            continue;
        }
        else
        {
            string j = "";
            while (i < n && s[i] != '/')
            {
                j += s[i];
                i++;
            }
            // i--;
            v.push_back(j);
        }
    }
    if (v.size() == 0)
    {
        cout << "/" << endl;
    }
    for (auto &val : v)
    {
        cout << '/' << val << " ";
    }
    return 0;
}