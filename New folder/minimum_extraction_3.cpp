#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int q = 0; q < n; q++)
    {
        int size;
        cin >> size;
        vector<signed long int> v;
        for (int i = 0; i < size; i++)
        {
            signed long int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        signed long int minimal = v[0];
        // cout<<v[0]<<endl;
        while (v.size() > 0)
        {
            signed long int curr = v[0];
            for (int a = 0; a < v.size(); a++)
            {
                v[a] = v[a] - curr;
            }
            v.erase(v.begin());
            if (curr >= minimal)
            {
                minimal = curr;
            }
            else{}
            // cout<<minimal<<endl;
        }
        cout << minimal << endl;
    }

    return 0;
}