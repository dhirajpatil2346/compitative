#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[m], arr2[m];
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        arr2[i] = x;
    }
    sort(arr, arr + m);
    sort(arr2, arr2 + m);
    int max = 0, min = 0, t = 0;
    bool k = 1;
    for (int i = 0; i < m; i++)
    {
        if (k)
        {
            while (arr[i] != 0)
            {
                min += arr[i];
                // cout<<min<<endl;
                t++;
                arr[i]--;
                if (t == n)
                {
                    k = 0;
                    break;
                }
            }
        }
    }
    t = 0;
    k = 1;

    while (k)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            if (k)
            {
                int key = arr2[m - 2];
                if (key < arr2[i])
                {
                    while (arr2[i] != arr2[i - 1])
                    {
                        max += arr2[i];
                        t++;
                        // cout << n << " " << t << " " << max << endl;
                        arr2[i]--;
                        if (t == n)
                        {
                            k = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (k)
        {
            // cout<<"ggghg"<<endl;
            max += arr2[m - 1];
            // cout << n << " " << t << " " << max << endl;
            t++;
            arr2[m - 1]--;
            if (t == n)
            {
                k = 0;
                break;
            }
            sort(arr2, arr2 + m);
        }
        
    }
    cout << max << " " << min;

        return 0;
}