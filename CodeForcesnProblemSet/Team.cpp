#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int j=0;
    for (int i = 0; i < n; i++)
    {
        stack<int> st;
        int y;
        int p,q,r;
        cin>>p>>q>>r;
        if(p==1){
            st.push(1);
        }
        if(q==1){
            st.push(1);
        }
        if(r==1){
            st.push(1);
        }
        if((st.size() > 1)){
            j++;
        }
    }
    cout<<j;
    return 0;
}