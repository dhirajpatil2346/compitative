#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    const int n = s.length();
    const int m = 1e9 + 7;
    const int p = 31;
    vector<LL> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * 1ll * p) % m;
    }

    vector<LL> hash(n);
    hash[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++)
    {
        hash[i] = (hash[i - 1] + (power[i] * 1ll * (s[i] - 'a' + 1)) % m) % m;
    }
    for (int l = l; l<= n; l++)
    {
        for (int i = 0; i < n-l; i++)
        {
            
        }
        
    }
    
    return 0;
}