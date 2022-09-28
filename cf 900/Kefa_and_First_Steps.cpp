#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int max = 0;
    if (n > 1)
    {
        for (int j = 0; j < n;)
        {
            // cout<<11<<endl;
            int curr = 1;
            int i = j;
            int m = i;
            while ((v[i] <= v[i + 1]) && (i < n - 1))
            {
                m++;
                j++;
                curr++;
                if (curr >= max)
                {
                    max = curr;
                }
            }
            j=m-1;
        }
    }
    else
    {
        max = 1;
    }
    cout << max;
    return 0;
}