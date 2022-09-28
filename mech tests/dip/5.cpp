#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &arr, int x)
{
    int closestSum = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (abs(x - closestSum) > abs(x - (arr[i] + arr[j] + arr[k])))
                {
                    closestSum = (arr[i] + arr[j] + arr[k]);
                }
            }
        }
    }
    return closestSum;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solution(arr, x) << endl;

    return 0;
}
