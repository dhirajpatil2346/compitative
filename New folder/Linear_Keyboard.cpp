#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int p = 0; p < n; p++)
    {
        /* code */
    
    
    string s;
    cin>>s;
    // cout<<s[0]<<endl;
    string j;
    cin>>j;
    // cout<<s.length()<<endl;
    // cout<<j.length()<<endl;
    vector<int> v;
    for (unsigned long int i = 0; i < j.length(); i++)
    {
        for (unsigned long int k = 0; k < s.length(); k++)
        {
            // cout<<s[i]<<endl;
            // cout<<j[k]<<endl;
            if (j[i] == s[k])
            {
                // cout<<s[i]<<endl;
                v.push_back(k+1);
            }
            else{}
            // cout<<"ejejeoj"<<v[i];
        }
    }
    // cout<<v.size();
    // for (int m = 0; m < v.size(); m++)
    // {
    //     cout<<v[m]<<"   ";
    // }
    // cout<<endl;
    int sum=0;
    for (int i = 1; i < v.size(); i++)
    {
        int y;
        y= (v[i] - v[i-1]);
        // cout<<sum<<endl;
        if(y >= 0){
            sum= sum + y;
        }
        else{
            sum = sum + ((-1) * y);
        }
        // cout<<sum<<endl;
    }
    cout<<sum<<endl;
    }
    return 0;
}