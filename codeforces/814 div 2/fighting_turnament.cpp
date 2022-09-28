#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> opeartion;
    int n, q;
    cin >> n >> q;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        opeartion.push_back(i);
        int x;
        cin >> x;
        m[i] = x;
    }
    map<int, int> ans;
    vector<pair<int, int>> queries;
    int op=0;
    for (int i = 0; i < q; i++)
    {
        int z,l;
        cin>>z>>l;
        queries.push_back({z,l});
        op=max(op, l);
    }
    while(op--)
    {
        
    }
    return 0;
}