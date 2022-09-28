#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n-1);   // for input aray
    for (int i = 0; i < n-1; i++)
    {
        cin >> v[i];
    }
    vector<int> path,ki;
    path.push_back(0);
    for (int i = 0; i < n-1; i++)
    {
        path.push_back(i+v[i]);
    }
    for (int i = 0; i < path.size(); i++)
    {
        if(path[i]==k-1)
        {
            ki.push_back(i);
        }
    }
    
    return 0;
}