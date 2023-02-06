#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    sort(v.begin(), v.end());

    cout << v[n - 1] << " ";
    for (int i = 1; i < n-1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[0] << endl;

    return 0;
}
/*
100 50 0 -50 -100
50 + 50 + 50 + 50

100 -50 0 50 -100
150 -50 -50 150 = 200

*/