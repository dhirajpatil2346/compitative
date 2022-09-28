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
        int height=0;
        while (n--)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        for (int i = 0; i < n-1; i++)
        {
            if(v[i] == 0 && v[i+1]){
                cout<<-1<<endl;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(v[i] == 0){
                height += (n-1-i);
            }
            else if(v[i]== 1){
                
            }
        }
        
        
    }
    
    return 0;
}