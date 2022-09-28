#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    unordered_set<int> x, y;
    for (int i = 0; i < n; i++)
    {
        int x1,y1;
        cin>>x1>>y1;
        x.insert(x1);
        y.insert(y1);
    }
    cout<<x.size()+y.size()<<endl;
    }
    return 0;
}