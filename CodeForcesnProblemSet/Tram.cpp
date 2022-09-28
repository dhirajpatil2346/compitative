#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // cout<<n<<endl;
    int fp = 0;
    int curr = 0;
    for (int j = 0; j < n; j++)
    {
        int o, i;
        cin>>o>>i;
        curr = curr + i - o;
        // cout<<"curr is"<<curr<<endl;
        if (curr >= fp)
        {
            fp = curr;
        }
        else
        {
        }
    }
    cout << fp;
    return 0;
}