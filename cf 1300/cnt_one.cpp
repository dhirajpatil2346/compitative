#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int i = 0;
    int score = 0;
    while (i < n)
    {
        if (v[i] == 0)
        {
            i++;
            continue;
        }
        int right = 0, left = 0;
        int j = i + 1;
        while (j < n && v[j] == 0)
        {
            j++;
            right++;
        }
        j = i - 1;
        while (j >= 0 && v[j] == 0)
        {
            j--;
            left++;
        }
        int mini = min(left, right), maxi = max(left, right);
        int cscore = max(mini, 1) * (maxi + 1);
        cout << i << " " << left << " " << right << " " << cscore << endl;
        score += cscore;
        i++;
    }
    cout << score << endl;
    return 0;
}