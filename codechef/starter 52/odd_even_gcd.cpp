#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> even, odd;
    for (auto &val : v)
    {
        cin >> val;
        if (val % 2)
        {
            odd.push_back(val);
        }
        else
        {
            even.push_back(val);
        }
    }
    sort(v.begin(), v.end());
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    // if odd is empty .. search for two


    // if even is empty.. search for one


    // else make match between them and search for one

    
    return 0;
}