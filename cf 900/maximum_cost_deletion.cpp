#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if (b >= a)
        {
            cout << n * (a + b) << endl;
        }
        else
        {
            vector<int> v;
            for (int i = 0; i < n;)
            {
                int cnt = 0;
                char c = s[i];
                while (s[i] == c)
                {
                    cnt++;
                    i++;
                }
                v.push_back(cnt);
            }
            /*
            for(auto &val:v)
            {
                cout<<val<<" ";
            }
            cout<<endl;
            */
            if (b<0 && s[0] == s[n - 1] && v.size() > 1)
            {
                v[0] += v[v.size() - 1];
                v.pop_back();
            }
            /*
            for(auto &val:v)
            {
                cout<<val<<" ";
            }
            cout<<endl;
            */
            long long cost = 0;
            for (auto &val : v)
            {
                cost += (a * val + b);
            }
            cout << cost << endl;
        }
    }
    return 0;
}