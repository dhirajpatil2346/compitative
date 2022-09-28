#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int c=0;
        for (int i = 0; i < n; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(a[j]-a[i] == j - i)
                {
                    c++;
                }

            }
        }
        cout<<c<<endl;
        
    }
    return 0;
}