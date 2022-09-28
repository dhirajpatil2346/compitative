#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pages;
    cin >> pages;
    int arr[7];
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int req = pages % sum;
    if (req != 0)
    {
        int ns = 0;
        for (int i = 0; i < 7; i++)
        {
            ns += arr[i];
            if (ns >= req)
            {
                cout << i + 1;
                break;
            }
        }
    }
    else
    {
        int nreq = sum;
        int ns = 0;
        for (int i = 0; i < 7; i++)
        {
            ns += arr[i];
            if (ns >= nreq)
            {
                cout << i + 1;
                break;
            }
        }
    }
    return 0;
}