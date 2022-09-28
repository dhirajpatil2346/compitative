#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v, int start, int end)
{
    vector<int> temp;
    for (int i = end; i >= start; i--)
    {
        temp.push_back(v[i]);
    }
    int i = start;
    for (auto &val : temp)
    {
        v[i] = val;
        i++;
    }
    /*
    for(auto &val:v)
        {
            //cout<<val<<" ";
        }
    */
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // cout<<"enter : ";
        cin >> v[i];
    }
    vector<int> v1 = v;
    sort(v1.begin(), v1.end());
    stack<int> s;
    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] != v[i])
        {
            start = i;
            break;
        }
    }
    for (int i = n; i >= 0; i--)
    {
        // cout<<i<<"  "<<v[i]<<endl;
        if (v1[i] != v[i])
        {
            end = i;
            break;
        }
    }
    if (start == end && start == -1)
    {
        cout << "yes" << endl
             << "1 1" << endl;
    }
    else
    {
        // cout << start << "  " << end << endl;
        reverse(v, start, end);
        /*
        for (auto &val : v)
        {
            cout << val << " ";
        }
        */
        bool got = false;
        for (int i = 0; i < n + 1; i++)
        {
            if (v1[i] != v[i])
            {
                got = true;
            }
        }
        if (got)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl
                 << start << " " << end << endl;
        }
    }
    return 0;
}