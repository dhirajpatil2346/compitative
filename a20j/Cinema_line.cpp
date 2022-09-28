#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int avail = 0;
    bool fault = false;
    int c25 = 0, c50 = 0;
    while (n--)
    {
        int x;
        cin >> x;
        // cout<<x<<"  "<<c25<<"   "<<c50<<endl;
        if (x - 25 > avail)
        {
            fault = true;
            break;
        }
        else if (x == 25)
        {
            c25++;
            avail += 25;
        }
        else if (x == 50)
        {
            if (c25 == 0)
            {
                fault = true;
                break;
            }
            else
            {
                c25--;
                c50++;
                avail += 25;
            }
            
        }
        else if (x == 100)
        {
            if (c25 == 0 )
            {
                fault = true;
                break;
            }
            else if (c50 == 0)
            {
                c25 -= 3;
            }
            else
            {
                c25--;
                c50--;
            }
            avail-=75;
        }
    }
    if (fault)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}