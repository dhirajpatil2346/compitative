#include <bits/stdc++.h>
using namespace std;
void print(unordered_map<int, string> &m)
{
    cout << m.size() << endl;
    map<int, string>::iterator it;
    for(auto v:m)
    {
        cout << v.first << "    " << v.second << "     ";
    }
}
int main()
{
    // 1. Inbuilt implementation
    // 2. Time complexity  //O(1)
    // 3. valid keys datatypes
    unordered_map<pair<int,int>, string> m;
    // m[1] = "abc"; // O(logn)
    // m[5] = "cdc";
    // m[3] = "acd";
    // m[6] = "a";
    // m[5] = "cde";
    // m["abcd"] = "abcd"; // s.size() * O(log(n))
    // auto im = m.find(7); // O(1)
    // if(im != m.end());
    // {
    //     m.erase(3); //O(logn)   
    // } 
    // m.clear();
    // if (im == m.end())
    // {
    //     cout << "NO VALUE     ";
    // }
    // else
    // {
    //     cout << (*im).first << "    " << (*im).second << "  ";
    // }
    // m.insert({4, "afg"});
    // map<int, string> :: iterator it;
    // for (auto it = m.begin(); it != m.end(); it++)

    // print(m);
    return 0;
}