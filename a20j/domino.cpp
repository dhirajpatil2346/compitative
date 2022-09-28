#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/353/A
int main()
{
    int n;
    cin >> n;
    int arr[n][2];
    int t1 = 0, t2 = 0, o1 = 0, o2 = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        sum1 += arr[i][0], sum2 += arr[i][1];
        if (arr[i][0] % 2 == 0 && arr[i][1] % 2 != 0)
        {
            o2++;
            t2++;
        }
        else if (arr[i][0] % 2 != 0 && arr[i][1] % 2 == 0)
        {
            o1++;
            t1++;
        }
    }
    int i = 0;
    int mv = 0;
    int did=false;
    while (i < n)
    {
        if (sum1 % 2 == 0 && sum2 % 2 == 0)
        {
            did=true;
            break;
        }
        if (arr[i][0] % 2 == 0 && arr[i][1] % 2 == 0)
        {
            continue;
        }
        if (arr[i][0] % 2 == 1 && arr[i][1] % 2 == 1)
        {
            continue;
        }
        if (sum1 % 2 == 1 && sum2 % 2 == 1)
        {
            if (arr[i][0] % 2 == 1 && arr[i][1] % 2 == 0)
            {
                did=true;
                mv++;
                sum2 = 0;
            }
            else if (arr[i][0] % 2 == 0 && arr[i][1] % 2 == 1)
            {
                did=true;
                mv++;
                sum1 = 0;
            }
        }
        else if (sum1 % 2 == 0 && sum2 % 2 == 1)
        {
            if (arr[i][0] % 2 == 1 && arr[i][1] % 2 == 0)
            {
                did=true;
                mv++;
                sum2 = 0;
            }
        }
        else if (sum1 % 2 == 1 && sum2 % 2 == 0)
        {
            if (arr[i][0] % 2 == 0 && arr[i][1] % 2 == 1)
            {
                did=true;
                mv++;
                sum1 = 0;
            }
        }
    }
    if(did)
    {
        cout<<mv<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}