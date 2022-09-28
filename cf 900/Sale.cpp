#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;
        if(x<0){
            v.push_back(x);
        }
    }
    if(v.size()==0){
        cout<<0<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    
    m = v.size();
    if(n<m){
        m=n;
    }
    /*
    for(auto val:v){
        cout<<val<<endl;
    }
    */
    int sum = *v.begin();
    auto it=v.begin();
    ++it;
    m--;
    while(m!=0){
        sum+=*it;
        // cout<<m<<"  "<<*it<<"    "<<sum<<endl;
        it++;
        m--;
    }
    cout<<(-1)*sum;
    return 0;
}