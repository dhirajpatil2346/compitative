#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, one = 0, two = 0, three = 0, four = 0, final = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 4)
        {
            four++;
        }
        else if (x == 3)
        {
            three++;
        }
        else if (x == 2)
        {
            two++;
        }
        else
        {
            one++;
        }
    }
    final += four;
    if(two%2)
    {
        final+=two/2;
        two=1;
    }
    else
    {
        final+=two/2;
        two=0;
    }
    int z = min(three, one);
    final+=z;
    three-=z;
    one-=z;
    final+=three;
    // three finished here
    

    if(one==0 && two)
    {
        final++;
        two=0;
    }
    else if(one==1 && two)
    {
        final++;
        two=0;
        one=0;
    }
    else if(two && one>=2)
    {
        final++;
        two=0;
        one-=2;
        if(one%4)
        {
            final+=(one/4)+1;
        }
        else
        {
            final+=(one/4);
        }
    } 
    else
    {
        if(one%4)
        {
            final+=(one/4)+1;
        }
        else
        {
            final+=(one/4);
        }
    }
    cout<<final<<endl;
    return 0;
}