#include<bits/stdc++.h>
using namespace std;

bool is_positive(int x){
    return x>0;
}z

int main(){
//     auto sum= [](int x, int y){return x+y;}; 
//     cout<<sum(2,3);
    vector<int> v = {2,-3,5};
    cout<<all_of(v.begin(), v.end(), is_positive);
    //any_of
    //none_of
    return 0;
}