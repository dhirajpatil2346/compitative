#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    cout<<v.size();
    // cout<<v[0].size();
    // cout<<v[0][0];
    // cout<<v[0][1];
    // cout<<v[0][2];3
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<"   ";
        
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> v[n];
    for (int i = 0; i < n; i++)
    {
        int N;
        cin>>N;
        for (int j = 0; j < N; j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
    printVec(v[i]);
        /* code */
    }
    
    return 0;
}