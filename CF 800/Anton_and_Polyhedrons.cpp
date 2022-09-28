#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m;
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;
    int t, sum = 0;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin>>s;
        sum+=m[s];
    }
    cout<<sum;
    return 0;
}