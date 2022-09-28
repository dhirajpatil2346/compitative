#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<vector<char>> v;
    // v={{'a','b'}, {'a', 'k'}};
    for (unsigned long int i = 0, j = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            cout<<"djjdfjh"<<endl;
            while (s[i] == '0')
            {
                cout<<"vnkvjvjv"<<endl;
                v[j].push_back(s[i]);
                i++;
                cout<<i<<endl;
            }
        }
        else if (s[i] == '1')
        {
            while (s[i] == '1')
            {
                v[j].push_back(s[i]);
                i++;
                cout<<i<<endl;
            }
        }
            j++;
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int z = 0; z < v[i].size(); z++)
        {
            cout << v[i][z];
        }
    }

    return 0;
}