#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
map<int, int> ind;
bool cmp(int a, int b)
{
    return (ind[a] < ind[b]);
}
int *distictElementArray(int *arr, int len)
{
    ind.clear();
    for (int i = 0; i < len; i++)
    {
        if (ind.find(arr[i]) == ind.end())
            ind[arr[i]] = i;
    }
    set<int> s;
    for (int i = 0; i < len; i++)
        s.insert(arr[i]);
    int sz = s.size();
    arr = new int[sz];
    int r = 0;
    for (auto &val : s)
        arr[r++] = val;
    sort(arr, arr + sz, cmp);
    return arr;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr = distictElementArray(arr, n);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}