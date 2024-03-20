#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int numLocalExtrema(vector<int> arr)
{
    int n = arr.size();
    int ret = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (((arr[i] > arr[i + 1]) && (arr[i] > arr[i - 1])) || ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1])))
        {
            ret++;
        }
    }
    return ret;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &val : arr)
        cin >> val;
    cout << numLocalExtrema(arr) << endl;
    return 0;
}