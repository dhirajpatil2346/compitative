#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        char c;
        cin >> s >> c;
        int cn = 0, len = s.length();
        vector<int> index;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == c)
            {
                index.push_back(i);
            }
        }
        int length = index.size();
        bool got=true;
        for (int i = 0; i < length; i++)
        {
            // cout<<index[i]<<"   "<<len-index[i]<<endl;
            if (index[i] >= 0 && (index[i] % 2 == 0) && ((len - index[i] - 1) % 2 == 0))
            {
                cout << "YES" << endl;
                got=false;
                break;
            }
        }
        if(got)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}