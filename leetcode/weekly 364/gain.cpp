#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        int mini = v[i];
        int pref = 0;
        for (int j = i; j >= 0; j--)
        {
            mini = min(mini, v[j]);
            pref += mini;
        }
        int suff = 0;
        mini = v[i];
        for (int j = i; j < n; j++)
        {
            mini = min(mini, v[j]);
            suff += mini;
        }
        cout << i << " " << pref << " " << suff << " " << pref + suff - v[i] << endl;
    }
    /*
    10
    1 5 2 5 6 4 6 3 2 5 
    1 6 5 10 16 17 23 20 17 22 
    10 21 16 25 21 15 13 7 4 5 
    
    */
    return 0;
}