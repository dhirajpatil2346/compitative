#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n, k, curr = 0,curr1=0;
    cin >> n >> k;
    deque<int> v,v1,v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        v1.push_back(x);
        v2.push_back(x);
        curr += x;
        curr1+=x;
    }
    if(curr<k)
    {cout<<-1<<endl;}
    else{
    //cout<<v.size()<<endl;
    int op1 = 0,op2=0;
    while (v1.size() && curr != k)
    {
        int f = v1.front(), b = v1.back();
        if (curr - f == k)
        {
            curr -= f;
            //cout<<f<<"  "<<curr<<endl;
            v1.pop_front();
        }
        else if (curr - b == k)
        {
            curr -= b;
            //cout<<b<<"  "<<curr<<endl;
            v1.pop_back();
        }
        else if(curr-f<k)
        {
            curr -= b;
            //cout<<b<<"  "<<curr<<endl;
            v1.pop_back();
        }
        else if(curr-b<k)
        {
            curr -= f;
            //cout<<f<<"  "<<curr<<endl;
            v1.pop_front();
        }
        else if(f>=b)
        {
            curr -= f;
            //cout<<f<<"  "<<curr<<endl;
            v1.pop_front();
        }
        else
        {
            curr -= b;
            //cout<<b<<"  "<<curr<<endl;
            v1.pop_back();
        }
        op1++;
    }
    while (v2.size() && curr1 != k)
    {
        int f = v2.front(), b = v2.back();
        if (curr1 - f == k)
        {
            curr1 -= f;
            //cout<<f<<"  "<<curr<<endl;
            v2.pop_front();
        }
        else if (curr1 - b == k)
        {
            curr1 -= b;
            //cout<<b<<"  "<<curr<<endl;
            v2.pop_back();
        }
        else if(curr-f<k)
        {
            curr1 -= b;
            //cout<<b<<"  "<<curr<<endl;
            v2.pop_back();
        }
        else if(curr-b<k)
        {
            curr1 -= f;
            //cout<<f<<"  "<<curr<<endl;
            v2.pop_front();
        }
        else if(f>b)
        {
            curr1 -= f;
            // cout<<f<<"  "<<curr<<endl;
            v2.pop_front();
        }
        else
        {
            curr1 -= b;
            // cout<<b<<"  "<<curr<<endl;
            v2.pop_back();
        }
        op2++;
    }
    cout<<min(op1,op2)<<endl;
    }
    }
    return 0;
}