#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int ret = 0;
    if ((m < 3) && (n < 3))
    {
        ret = 0;
        // cout<<ret<<endl;
    }
    else if ((m >= 3) && (n <= 3))
    {
        if ((m / 3) <= n)
        {
            ret = m / 3;
        }
        else
        {
            ret = n;
        }
    }
    else if ((m <= 3) && (n >= 3))
    {
        if ((n / 3) <= m)
        {
            ret = n / 3;
        }
        else
        {
            ret = m;
        }
    }
    else
    {
        int f;
        if (m > n)
        {
            f = m / 3;
            m -= f * 3;
            ret += f;
            n -= f;
            if (n / 3 >= m)
            {
                ret += m;
            }
            else
            {
                ret += n / 3;
            }
        }
        else if(m<n)
        {
            f = n / 3;
            n -= f * 3;
            ret += f;
            m -= f;
            if (m / 3 >= n)
            {
                ret += n;
            }
            else
            {
                ret += m / 3;
            }
        }
        else{
            f=m/3;
            n-=f*3;
            ret+=f;
            m-=f;
            if (m / 3 >= n)
            {
                ret += n;
            }
            else
            {
                ret += m / 3;
            }
        }
    }
    cout << ret;
    return 0;
}