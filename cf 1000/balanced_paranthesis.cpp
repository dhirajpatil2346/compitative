#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    vector<int> v(n);
    int ans=0;
    int c0 = 0, c1 = 0, c2 = 0, req = n / 3;
    for (auto &val : v)
    {
        cin >> val;
        if (val % 3 == 0)
        {
            c0++;
        }
        else if (val % 3 == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    int r0,r1,r2,a0,a1,a2;
    if(c0>req)
    {
        a0=c0-req;
        r0=0;
    }
    else
    {
        a0=0;
        r0=req-c0;
    }
    if(c1>req)
    {
        a1=c1-req;
        r1=0;
    }
    else
    {
        a1=0;
        r1=req-c1;
    }
    if(c2>req)
    {
        a2=c2-req;
        r2=0;
    }
    else
    {
        a2=0;
        r2=req-c2;
    }
    /*
    cout<<c0<<" "<<r0<<"    "<<a0<<endl;
    cout<<c1<<" "<<r1<<"    "<<a1<<endl;
    cout<<c2<<" "<<r2<<"    "<<a2<<endl;
    */
// for 0
    if(r0>0)
    {
        if(a2>0)
        {
            int c = min(r0, a2);
            r0-=c;
            a2-=c;
            ans+=c;
        }
    }
    if(r0>0)
    {
        if(a1>0)
        {
            int c = min(r0, a1);
            r0-=c;
            a1-=c;
            ans+=2*c;
        }
    }

// for 1
    if(r1>0)
    {
        if(a0>0)
        {
            int c = min(r1, a0);
            r1-=c;
            a0-=c;
            ans+=c;
        }
    }
    if(r1>0)
    {
        if(a2>0)
        {
            int c = min(r1, a2);
            r1-=c;
            a2-=c;
            ans+=2*c;
        }
    }

// for 2
    if(r2>0)
    {
        if(a1>0)
        {
            int c = min(r2, a1);
            r2-=c;
            a1-=c;
            ans+=c;
        }
    }
    if(r2>0)
    {
        if(a0>0)
        {
            int c = min(r2, a0);
            r2-=c;
            a0-=c;
            ans+=2*c;
        }
    }

    cout<<ans<<endl;
    }
    return 0;
}