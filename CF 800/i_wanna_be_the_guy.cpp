#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_set<int> s;
    int y;
    cin>>y;
    for (int i = 0; i < y; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    int j;
    cin>>j;
    for (int i = 0; i < j; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    if(s.size()==n){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    return 0;
}