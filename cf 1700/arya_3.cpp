#include <bits/stdc++.h>
using namespace std;

vector<int> checkMatchingStrings(vector<string> words1, vector<string> words2)
{
    vector<int> ret;
    int n = words1.size();
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        if (words1[i].length() != words2[i].length())
        {
            ret.push_back(0);
            continue;
        }
        bool done = false;
        vector<char> v1, v2;
        for (auto &val : words1[i])
       
            v1.push_back(val);
        for (auto &val : words2[i])
            v2.push_back(val);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int j = 0; j < words1[i].size(); j++)
        {
            if (done)
                break;
            if (v1[j] == v2[j])
                continue;
            if (v1[j] > v2[j])
            {
                ret.push_back(0);
                done = true;
                break;
            }
            int x = j;
            int diff = v2[j] - v1[j];
            if ((diff < 0) || j == (words1[j].size() - 1))
            {
                ret.push_back(0);
                done = true;
                break;
            }
            if (done)
                break;
            while (x < words1[i].size() && (v1[j] == v1[x]))
            {
                int cdiff = v2[x] - v1[x];
                if (cdiff <= diff)
                    v1[x] += diff;
                x++;
            }
        }
        if (done)
            continue;
        else
            ret.push_back(1);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v1(n), v2(n);
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    vector<int> v = checkMatchingStrings(v1, v2);
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
    return 0;
}