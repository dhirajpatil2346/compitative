#include<bits/stdc++.h>
using namespace std;

int main(){
    //seq Sheldon Penny Rajesh Howard
    queue<char> q;
    q.push('s');
    q.push('l');
    q.push('p');
    q.push('r');
    q.push('h');
    int n;
    cin>>n;
    char curr ;
    for(int i = 0 ; i < n ; i++)
    {
        curr = q.front();
        q.pop();
        q.push(curr);
        q.push(curr);
    }
    if(curr=='s')
    {
        cout<<"Sheldon"<<endl;
    }
    else if(curr=='l')
    {
        cout<<"Leonard"<<endl;
    }
    else if(curr=='p')
    {
        cout<<"Penny"<<endl;
    }
    else if(curr=='r')
    {
        cout<<"Rajesh"<<endl;
    }
    else if(curr=='h')
    {
        cout<<"Howard"<<endl;
    }
    return 0;
}