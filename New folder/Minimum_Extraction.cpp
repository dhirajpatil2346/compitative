#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int q = 0; q < n; q++)
    {
        int info;
        int size;
        cin >> size;
        int maxi;
        vector<int> v;
        vector<int> minimal;
        for (int i = 0; i < size; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        while (v.size() > 0)
        {
            int minimum = v[0];
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] <= minimum)
                {
                    minimum = v[j];
                    info = j;
                }
                else
                {
                }
            }
            minimal.push_back(minimum);
            int temp;
            temp = v[info];
            v[info] = v[v.size() - 1];
            v[v.size() - 1] = temp;
            v.pop_back();
            for (int a = v.size(); a >= 0; a--)
            {
                if (v[a] >= minimum)
                {
                    v[a] = v[a] - minimum;
                }
                else
                {
                }
            }
            // maxi = v[0];
            // for (int i = 0; i < v.size(); i++)
            // {
            //     if (((v[i] >= maxi) && v[i] != minimum))
            //     {
            //         maxi = v[i];
            //     }
            // }
        }
        int minimali = minimal[0];
        for (int i = 0; i < minimal.size(); i++)
        {
            if (minimali < minimal[i])
            {
                minimali = minimal[i];
            }
            else
            {
            }
        }
        cout << minimali<<endl;
    }
    return 0;
}