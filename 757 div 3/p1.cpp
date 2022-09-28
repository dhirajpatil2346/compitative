#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int j = 0; j < t; j++)
    {
        /* code */
    
    
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int sum=0,choco=0;
    int start=0,end=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==l){
            start=i;
            break;
        }
        else if(v[i]>l){
            start=i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(v[i]==r){
            end=i;
            break;
        }
        else if(v[i]>r){
            end=i-1;
            break;
        }
    }
    // cout<<start<<endl<<end<<endl;
    int tom;
    for (int i = start; i < end+1; i++)
    {
        sum+=v[i];
        if(sum<=k){
            choco++;
        }
        else if(i==end){
             cout<<choco<<endl;
            // cout<<"else"<<endl;
            tom=0;
        }
        else{
            cout<<choco<<endl;
            // cout<<"else"<<endl;
            tom=0;
            break;
        }
        if((i==end)&&(tom!=0)){
            cout<<choco<<endl;
        }
    }
    }
    return 0;
}