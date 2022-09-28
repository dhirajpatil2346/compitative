#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if(k<=n)
        {
            cout<<k<<endl;
        }
        else{
            int j = k%n - 1;
            cout<<j<<endl;
        }
    }
    return 0;
}