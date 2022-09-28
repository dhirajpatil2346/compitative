#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> x;
    vector<int> y;
    vector<int> z;
    for (int i = 0; i < n; i++)
    {   
        int k, l, m;
        cin>>k>>l>>m;
        x.push_back(k);
        y.push_back(l);
        z.push_back(m);
    }
    int q=0, w=0, e=0;
    for (int i = 0; i < n; i++)
    {
        q+=x[i];
    }
    for (int i = 0; i < n; i++)
    {
        w+=y[i];
    }
    for (int i = 0; i < n; i++)
    {
        e+=z[i];
    }
    if((q==0) && (q==w) && (w==e)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}