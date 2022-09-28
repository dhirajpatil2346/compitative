#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int value = 0;
        for (auto &val : s)
        {
            if (val == '1')
            {
                value++;
            }
        }
        if (value == 0)
        {
            cout << n * k << endl;
        }
        else if(value==n)
        {
            if((n*k)%2)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<1<<endl;
            }
        }
        
        else
        {
            int pre = 0, suff = 0;
            vector<int> prefix(s.length()), suffix(s.length());
            for (int i = s.length() - 1; i >= 0; i--)
            {
                suffix[i] = suff;
                if (s[i] == '1')
                {
                    suff++;
                }
            }
            int a = 0;
            // cout<<"value is "<<value<<endl;
            for (int i = 0; i < k; i++)
            {
                int po = 0, so = 0;
                if (i == 0)
                {
                    so = (k - 1) * value;
                }
                else if (i == k - 1)
                {
                    po = (k - 1) * value;
                }
                else
                {
                    po = i * value;
                    so = (k - 1 - i) * value;
                }
                vector<int> cp(n), cs(n);
                int pp = po, ss = so;
                for (int z = 0; z < n; z++)
                {
                    if (s[z] == '1')
                    {
                        pp++;
                    }
                    cp[z] = pp;
                }
                for (int z = n - 1; z >= 0; z--)
                {
                    cs[z] = ss;
                    if (s[z] == '1')
                    {
                        ss++;
                    }
                }
                for (int z = 0; z < n; z++)
                {
                    if (cp[z] == cs[z])
                    {
                        a++;
                    }
                }
            }
            cout << a << endl;
        }
    }
    return 0;
}