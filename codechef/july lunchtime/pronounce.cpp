#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n >= 4)
        {
            bool got = false;
            vector<int> a;
            vector<char> v = {'a', 'e', 'i', 'o', 'u'};
            for (int i = 0; i < n; i++)
            {
                char key = s[i];
                bool cg = false;
                for (auto &val : v)
                {
                    if (val == key)
                    {
                        cg = true;
                        break;
                    }
                }
                if (cg)
                {
                    a.push_back(1);
                }
                else
                {
                    a.push_back(0);
                }
            }
            /*
            for (auto &val : a)
            {
                cout << val;
            }*/
            for (int i = 0; i < n - 3; i++)
            {
                // cout<<endl<<"     "<<i;
                if(got)
                {
                    break;
                }
                if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 0)
                {
                    got = true;
                    break;
                }
            }
            // cout<<endl<<got<<endl;
            if(got)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}