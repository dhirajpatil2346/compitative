#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v = {'H', 'Q', '9'};
    string s;
    getline(cin, s);
    // cout << s.length() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.find(v[i]) < s.length())
        {
            cout<<"YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}