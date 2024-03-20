#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int maxop(int *list, int len)
{
    int o = 0;
    for (int i = 1; i < len; i++)
        if (list[i] < list[i - 1])
            o++;
    if (o == 0)
        return 0;
    int ret = 1;
    for (int i = 1; i <= o; i++)
        ret *= o;
    return ret;
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
    cout << maxop(arr, n) << endl;
    return 0;
}