#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

bool cpm(int a , int b){
    return a>b;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (should_i_swap(a[i], a[j]))
    //         {
    //             swap(a[i], a[j]);
    //         }
    //     }
    // }
    sort(a.begin(), a.end(), cmp);
    // sort(a.begin(), a.end(), greater<pair<int, int>> ());
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << "   " << a[i].second << endl;
    }
    return 0;
}