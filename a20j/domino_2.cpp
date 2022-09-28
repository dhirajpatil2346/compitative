#include <bits/stdc++.h>
using namespace std;
/*
1 0
2 0
3 3
4 2
5 5
6 3
*/
int main()
{
    int n;
    cin >> n;
    vector<int> v(n), v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> v1[i];
    }
    int s1 = accumulate(v.begin(), v.end(), 0);
    int s2 = accumulate(v1.begin(), v1.end(), 0);
    // cout<<s1<<" "<<s2<<endl;
    // cout<< (!s1 % 2 && !s2 % 2) <<endl;
    if ((s1 % 2==0 && s2 % 2==0) )
    {
        cout << 0 << endl;
    }
    else if((s1%2==0 && s2%2==1) ||( s1%2==1 && s2%2==0) )
    {
        cout<<-1<<endl;
    }
    else
    {
        bool got = false;

        for (int i = 0; i < n; i++)
        {
            if ((v[i] % 2 && v1[i] % 2==0) || (v[i] % 2 == 0 && v1[i] % 2))
            {
                got = true;
                break;
            }
        }

        if (!got)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}