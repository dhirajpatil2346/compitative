#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v(1e6 + 1);
    for (int i = 0; i < 1e6 + 1; i++)
    {
        v[i] = i;
    }
    for (int i = 2; i * i <= (1e6 + 1); i++)
    {
        if (v[i] != i)
        {
            continue;
        }
        for (int j = i * i; j <= 1e6 -; j += i)
        {
            v[j] = i;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}