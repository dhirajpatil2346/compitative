#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    // vector<int>::iterator it = v.begin();
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        /* code */
        cout << *(it) << " ";
    }
    for (int value : v){
        value++;
        cout<<value<<"   ";
    }
    vector<pair<int, int> > v_p = {{1,2}, {2,3}};
    for (auto value : v_p){
        cout<<value.first<<" "<<value.second<<endl;
    }
    auto a = 1.0;
    cout<<a<<endl;
    return 0;
}