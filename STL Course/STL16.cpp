#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    auto it = lower_bound(a.begin(), a.end(), 6);
    if (it == a.end())
    {
        cout << "Not found" << endl;
        return 0;
    }
    cout << (*it);
    */

    int n;
    cin >> n;
    set<int> s;
    map<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    auto it = s.lower_bound( 5);
    cout << (*it)<<endl;;
    return 0;
}