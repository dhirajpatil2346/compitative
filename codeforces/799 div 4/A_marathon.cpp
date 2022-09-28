#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> v(4);
        for(auto &val:v){cin>>val;}
        int key = v[0];
        int r=0;
        for (int i = 1; i < 4; i++)
        {
            if(v[i]>key)
            {
                r++;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}