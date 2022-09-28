#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    };
    int mini = INT_MAX, minId = 0;
    int pi = -1;
    int curr = 0;
        for (int j = 0; j < k; j++)
        {
            curr += v[j];
        }
        pi = 0;
        mini=curr;
    // cout<<curr<<endl;
    for (int i = k; i < n; i++)
    {
        // cout << curr << endl;
        curr -= v[pi];
        curr += v[i];
        if (curr < mini)
        {
            mini = curr;
            minId = pi+1;
        }
        pi++;
    }
    cout <<minId + 1 << endl;
    return 0;
}