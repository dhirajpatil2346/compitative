#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> us = {1,2,3};
    unordered_set<int> us1 = {1,4,3};
    us.insert(us1.begin(), us1.end());
    for(auto &val:us)
    {
        cout<<val<<" ";
    }
    return 0;
}