#include <bits/stdc++.h>
using namespace std;

void lr(vector<int> &v)
{
    for (int i = 0; i < 4; i++)
    {
        int temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
    }
}

int main()
{
    int arr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> v(5);
    int z = 0;
    for (int i = 0; i < 5; i++)
    {
        v[i] = z;
        z++;
    }
    /*
    for (auto i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }
    cout<<endl;
    */
    int maxi = INT_MIN;
    int curr = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int k = j + 1; k < 5; k += 2)
        {
            curr += arr[v[k - 1]][v[k]];
            curr += arr[v[k]][v[k - 1]];
        }
    }
    maxi = max(curr, maxi);
    // cout<<maxi<<endl;
    for (int i = 0; i < 5; i++)
    {
        curr = 0;
        for (int j = 0; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k += 2)
            {
                curr += arr[v[k - 1]][v[k]];
                curr += arr[v[k]][v[k - 1]];
            }
        }
        lr(v);
        for(auto &val:v)
        {
            cout<<val;
        }
        cout<<" " <<curr<<endl;
        maxi = max(curr, maxi);
        // cout<<curr<<"   "<<maxi<<endl;
    }
    cout << maxi << endl;
    return 0;
}