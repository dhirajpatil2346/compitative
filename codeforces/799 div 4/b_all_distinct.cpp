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
        unordered_set<int> us;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            us.insert(x);
        }
        int op = (n-us.size())/2 + (n-us.size())%2;
        int c = 2*op;
        cout<<n-c<<endl;
    }
    return 0;
}