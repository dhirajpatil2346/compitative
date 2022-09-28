#include <bits/stdc++.h>
using namespace std;

int ret (vector<int> &nums)
{
    int numN = 0;
    for(auto item:nums)
    {
        if(item==0)
        {
            return 0;
        }
        if(item<0)
        {
            numN++;
        }
    }
    return !(numN%2) ?1:-1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    return 0;
}