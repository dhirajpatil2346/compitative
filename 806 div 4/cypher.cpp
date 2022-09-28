#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin >> n;
    vector<int> key(n);
    vector<int> ans(n);
    for (auto &val : key)
    {
        cin >> val;
    }
    for (int i = 0; i < n; i++)
    {
        int op;
        string s;
        cin >> op;
        cin >> s;
        int curr = key[i];
        for (int j = 0; j < op; j++)
        {
            if(s[j]=='D')
            {
                curr++;
                if(curr==10)
                {
                    curr=0;
                }
            }
            if(s[j]=='U')
            {
                curr--;
                if(curr==-1)
                {
                    curr=9;
                }
            }
        }
        ans[i]=curr;;
    }
    for(auto &val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    }
    return 0;
}