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
        vector<int> v(n);
        int front = 0, back = n - 1;
        int act = n / 2;
        while (front < back && act--)
        {
            // cout<<front<<" "<<back<<" "<<s[front]<<" "<<s[back]<<endl;
            while (front < back && s[front] == s[back])
            {
                v[front] = 1, v[back] = 1;
                front++, back--;
            }
            if (front < back && s[front] != s[back])
            {
                if (s[front] == s[back - 1])
                {
                    v[back--] = -1;
                }
                else
                {
                    v[front++] = -1;
                }
            }
            // cout<<front<<"  "<<back<<endl;
        }
        /*
        for(auto &val:v)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        */
        string a = "";
        int i = 0;
        for (auto &val : v)
        {

            if (val == -1)
            {
                i++;
                continue;
            }
            a += s[i];
            i++;
        }
        cout << a << endl;
    }
    return 0;
}