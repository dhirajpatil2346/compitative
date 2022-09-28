#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int len;
    cin>>len;
    vector<int>v;
    for (int i = 0; i < len; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int size=v.size();
    bool ans = false;
    for (int i = 0; i < size; i++)
    {
        vector<int> vd=v;
        int Z=0;
        for (auto it = vd.begin(); it != vd.end(); it++, Z++)
        {
            int n = sizeof(v) / sizeof(v[Z]);
            int count = (v.begin(), v.begin() + )
        }
        
    }
    
    return 0;
}