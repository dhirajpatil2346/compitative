#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int one = 0, two = 0, three = 0, four = 0;
    for (auto &val : v)
    {
        cin >> val;
        if (val == 1)
        {
            one++;
        }
        else if (val == 2)
        {
            two++;
        }
        else if (val == 3)
        {
            three++;
        }
        else
        {
            four++;
        }
    }
    int final = 0;
    if (two % 2)
    {
        if (three == one)
        {
            final += three + four + two / 2 + 1;
        }
        else if (three < one && ((one - three) % 4))
        {
            final = three + four + (one - three) / 2 + two / 2;
        }
        else if (three < one && (!(one - three) % 4))
        {
            final = three + four + (one - three) / 2 + two / 2 + 1;
        }
        else if (three > one)
        {
            final = three + four + two / 2 + 1;
        }
        else if (three > one)
        {
            final = three + four + two / 2 + 1;
        }
    }
    return 0;
}