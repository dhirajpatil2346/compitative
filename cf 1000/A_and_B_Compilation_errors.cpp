#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n - 1), v3(n - 2);
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (auto &val : v1)
    {
        cin >> val;
        sum1+=val;
    }
    for (auto &val : v2)
    {
        cin >> val;
        sum2+=val;
    }
    for (auto &val : v3)
    {
        cin >> val;
        sum3+=val;
    }
    cout<<sum1-sum2<<endl<<sum2-sum3<<endl;
    return 0;
}