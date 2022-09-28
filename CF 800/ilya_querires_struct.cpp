#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int arr[n][2];
    map<int, vector<int>> m;
    map<int, map<int, int>> sol;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        m[arr[i][0]].push_back(arr[i][1]);
    }
    return 0;
}