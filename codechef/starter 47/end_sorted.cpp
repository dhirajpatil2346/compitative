#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    int n;
    cin >> n;
    int ans = 0;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v[i] = val;
    }
    int find1 = 0, findn = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            find1 = i;
        }
    }
    // cout<<"find1 is "<<find1<<endl;
    if (find1 != 0)
    {
        int c = find1;
        while (c > 0)
        {
            ans++;
            swap(v + c, v + c - 1);
            c--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == n )
        {
            findn = i;
        }
    }

    // cout<<"findn is "<<findn<<endl;
    if (findn != n )
    {
        int c = findn;
        while (c < n - 1)
        {
            ans++;
            swap(v + c, v + c + 1);
            c++;
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}