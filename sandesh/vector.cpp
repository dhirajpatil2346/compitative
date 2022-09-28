#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

int main(){
    /*
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // vector<int> :: iterator it;
    // for(auto it=v.rbegin() ; it != v.rend();it++)
    // {
    //     cout<<*it<<' ';
    // }
    // cout<<endl;
    sort(v.begin(), v.end(), cmp);
    for(auto it=v.begin() ; it != v.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    */
   int n;
   cin>>n;
   vector<vector<int>> v(n);

   for (int i = 0; i < n; i++)
   {
       int x;
       cin>>x;
       for (int j = 0; j < x; j++)
       {
           int k;
           cin>>k;
           v[i].push_back(k);
       }

   }
   /*
   for (int i = 0; i < n; i++)
   {
       int x = v[i].size();
       for (int j = 0; j < x; j++)
       {
           cout<<v[i][j]<<"\t";
       }
       cout<<endl;
   }
   */

    // vector<vector<int>> :: iterator itr;
    for (auto itr = v.begin(); itr != v.end(); itr++)
    {
        for (int i = 0; i < (*itr).size(); i++)
        {
            cout<<(*itr)[i]<<"\t";
        }
        cout<<endl;
    }
    
    return 0;
}