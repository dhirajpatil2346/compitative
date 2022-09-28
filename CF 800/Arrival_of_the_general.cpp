#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cin >> arr[0];
    int max = arr[0], mi = 0, min = arr[0], mni = 0;
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > max && a != max)
        {
            // cout<<a<<"  "<<max<<endl;
            max = a;
            mi = i;
        }
        if (a <= min)
        {
            // cout << a << "  " << max << endl;
            min = a;
            mni = i;
        }
    }
    int maxd = mi;
    int mind = (n - 1) - mni;
    if(mi<=mni){
    cout << maxd + mind<<endl;
    }
    else{
        cout<<maxd+mind-1;
    }
    return 0;
}