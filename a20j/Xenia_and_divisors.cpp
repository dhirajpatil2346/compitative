/*
1 2 4
1 2 6
1 3 6
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int req=n/3;
    map<int, int> m;
    int e6 = 0, e4 = 0, e3 = 0, e2 = 0, e1 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            e1++;
        }
        else if (x == 2)
        {
            e2++;
        }
        else if (x == 3)
        {
            e3++;
        }
        else if (x == 4)
        {
            e4++;
        }

        else if (x == 6)
        {
            e6++;
        }
        /*
        if(m.count(x))
        {
            m[x]++;
        }
        else{
            m[x]=1;
        }
        */
    }
    int p1 = 0, p2 = 0, p3 = 0;
    // cout<<e1<<"   "<<e2<<"  "<<e3<<"  "<<e4<<"  "<<e6<<endl;
    if (e1 > 0 && e2 > 0 && e4 > 0)
    {
        p1 = min(e1, e2);
        // cout<<p1<<endl;
        p1 = min(p1, e4);
        // cout<<p1<<endl;
        e1 -= p1, e2 -= p1, e4 -= p1;
    }

    if (e1 > 0 && e2 > 0 && e6 > 0)
    {
        p2 = min(e1, e2);
        p2 = min(p2, e6);
        e1 -= p2, e2 -= p2, e6 -= p2;
    }

    if (e1 > 0 && e3 > 0 && e6 > 0)
    {
        p3 = min(e1, e3);
        p3 = min(p3, e6);
        e1 -= p3, e3 -= p3, e6 -= p3;
    }
    // cout<<p1<<"  "<<p2<<"  "<<p3<<" "<<endl;
    int done=p1+p2+p3;
    if(done!=req)
    {
        cout<<-1;
        return 0;
    }
    for (int i = 0; i < p1; i++)
    {
        cout << "1 2 4" << endl;
        // done++;
    }
    for (int i = 0; i < p2; i++)
    {
        cout << "1 2 6" << endl;
        // done++;
    }
    for (int i = 0; i < p3; i++)
    {
        cout << "1 3 6" << endl;
        // done++;
    }
    
    return 0;
}