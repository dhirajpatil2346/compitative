#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long pn = 0;
    long long ans = 0;
    long long start = 5, curr = 1, inc = 5;
    vector<string> v = {"","Sheldon", "Leonard", "Penny", "Rajesh" , "Howard" };
    if (start >= n)
    {
        long long m = n - pn;
        if (m % curr)
        {
            ans = m / curr + 1;
        }
        else
        {
            ans = m / curr;
        }
    }
    else
    {
        pn = 5;
        while (true)
        {
            start += 2 * inc;
            curr *= 2;
            inc *= 2;
            // cout << start << endl;
            if (start >= n)
            {
                long long m = n - pn;
                if (m % curr)
                {
                    ans = m / curr + 1;
                }
                else
                {
                    ans = m / curr;
                }
                break;
            }
            pn = start;
        }
    }
    cout << v[ans] << endl;
    return 0;
}