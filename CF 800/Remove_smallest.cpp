#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        bool ans=false;
        while (n--)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size()-1; i++)
        {
            if((v[i+1]-v[i]) > 1){
                cout<<"NO"<<endl;
                ans=true;
            }
        }
        if(ans==false){
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}