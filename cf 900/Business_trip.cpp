#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < 12; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int sum=0;
    int j=0;
    auto itm  = v.begin();
    auto it = v.rbegin();
    while(sum<n){
        sum+=*(it);
        if(*it==*(v.rend())){
            if(sum!=n){
                cout<<-1<<endl;
                return 0;
            }
        }
        it++;
        j++;
    }
    cout<<j;
    return 0;
}