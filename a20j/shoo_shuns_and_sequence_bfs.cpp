// https://codeforces.com/problemset/problem/222/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int front = 0;
    int j = k;
    int mv = 0;
    bool loop = true;
    bool got = false;
        int key = v[front];
    for (int i = front; i < v.size(); i++)
    {
        if (v[i] != key)
        {
            got = true;
            break;
        }
    }
    if (!got)
    {
        loop = false;
    }
    while (loop && j--)
    {
        mv++;
        got = false;
        v.push_back(v[k + front - 1]);
        // cout<<v[front+k-1]<<" ";
        front++;
         key = v[front];
        for (int i = front; i < v.size(); i++)
        {
            if (v[i] != key)
            {
                got = true;
                break;
            }
        }
        if (!got)
        {
            loop = false;
        }
    }
    // cout<<endl;
    // cout << front << endl;
     key = v[front];
    bool fault = false;
    for (int i = front; i < v.size(); i++)
    {
        // cout<<v[i]<<" ";
    }
    // cout<<endl;
    for (int i = front; i < v.size(); i++)
    {
        if (v[i] != key)
        {
            fault = true;
            break;
        }
    }
    if (fault)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mv << endl;
    }
    return 0;
}