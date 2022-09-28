#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    // cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        // v.size() ->O(1)
        cout << v[i] << " ";
    }
    // v.push_back(2);
    cout << endl;
}

int main(){
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    for (auto value : v)
    {
        cout<<value;
    }
    
    // printVec(v);
    return 0;
}