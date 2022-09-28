#include<bits/stdc++.h>
using namespace std;
void print(multiset<string> &s){
    for (string value : s)
    {
        cout<<value<<endl;
    }
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout<<(*it)<<endl;
    // }
}
int main(){
    multiset<string> s;
    s.insert("abc");  //O(logn)
    s.insert("zsdf");
    s.insert("abc");
    s.insert("bcd");
    // auto it = s.find("abc");  // O(log(n))
    // if(it != s.end()){
    //    s.erase(it);
    // }
    // s.erase("bcd");
    print(s);
    return 0;
}