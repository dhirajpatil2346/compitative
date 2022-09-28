#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;

    // for maxi
    ll maxi = 0;
    // step 1 : make teams of player 1 = m-1
    ll z = n - (m - 1);
    maxi = (z * (z - 1)) / 2;
    // cout << maxi << endl;

    // for mini
    ll mini = 0;
    // step 1 : if(n%m == 0) :: then do reaction of n/m with m
    // else :
    // do reaction of (n%m) with (n/m + 1) and n-(n%m) with (n/m)
    if (n % m == 0)
    {   
        mini = m * (((n / m) * ((n / m) - 1)) / 2);
    }
    else
    {
        mini = (n % m) * ((((n / m) + 1) * (n / m)) / 2) + (m - (n % m)) * (((n / m) * ((n / m) - 1)) / 2);
    }
    cout << mini << " " << maxi << endl;
    return 0;
}