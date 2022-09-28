#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n, m, k;
    string s, z;
    cin >> n >> m >> k >> s >> z;
    // cout << n << m << k << s << z << endl;
    vector<char> c1, c2;
    for (int i = 0; i < n; ++i)
    {
        c1.push_back(s[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        c2.push_back(z[i]);
    }
    int f1 = 0, f2 = 0;
    // cout<<"c2 is    ";
    // for(auto &val:c2){cout<<val;}
    // cout<<endl;
    sort(c1.begin(), c1.end());
    
    sort(c2.begin(), c2.end());
    string ss = "";
    /*
    for (int i = 0; i < n; i++)
    {
        cout<<c1[i];
    }
    cout<<endl;   
    for (int i = 0; i < m; i++)
    {
        cout<<c2[i];
    }
    cout<<endl; 
    */  
    int a1 = 0,
    a2 = 0;
    while (f1 < n && f2 < m)
    {
        // cout<<"running"<<endl;
        if (a1 < k && c1[f1] <= c2[f2])
        {
            a2 = 0;
            a1++;
            ss += c1[f1];
            f1++;
        }
        else
        {
            ss += c2[f2];
            f2++;
            a1 = 0;
            a2++;
        }
        // cout << ss << endl;
    }
    cout << ss << endl;
    }
    return 0;
}