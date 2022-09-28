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
            signed long int x;
            cin >> x;
            v.push_back(x);
        }
        while (v.size() > 0)
        {
            // find minimum
            auto minimumIndex = min_element(v.begin(), v.end());
            signed long int minimum = *(min_element(v.begin(), v.end()));
            minimal.push_back((minimum));
            // erase
            v.erase(minimumIndex);
            // creating new array
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
        }
        cout<<*(max_element(minimal.begin(), minimal.end()))<<endl;
    }

    return 0;
}