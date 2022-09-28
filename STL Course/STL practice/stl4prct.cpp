#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> v;
    v = {{1, 2},{1 , 3}};
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout<<(*it).first<<"  "<<(*it).second<<"  ";
    }
    
    return 0;
}