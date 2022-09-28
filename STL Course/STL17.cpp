#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min = (*min_element(v.begin(), v.end()));
    int max = (*max_element(v.begin(), v.end()));
    int sum = accumulate(v.begin(), v.end(), 0);
    int ct = count(v.begin(), v.end(), 6);
    auto it = find(v.begin(), v.end(), 2);
    cout << min << endl
         << max << endl
         << sum << endl
         << ct << endl;
    if (it != v.end())
    {
        cout << *it << endl;
    }
    else
    {
        cout << "Element not found";
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i]<<" ";
    }
    cout<<endl;
    string s = "ahvjvjj";
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}