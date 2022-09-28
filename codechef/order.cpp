#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int x = 0; x < n; x++)
    {
        string s;
        cin >> s;
        vector<char> v;
        long long int order = 0;
        for (unsigned long int i = 0; i < s.length(); i++)
        {
            v.push_back(s[i]);
        }
        sort(v.begin(), v.end());
        // for (unsigned long int k = 0; k < s.length(); k++)
        // {
        //     cout << v[k] << "   ";
        // }
        // cout << endl;
        for (unsigned long int i = 0; i < s.length(); i++)
        {
            order += ((i + 1) * (v[i] - 96));
        }
        cout << order << endl;
    }
    return 0;
}