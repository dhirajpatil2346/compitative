#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(const pair<int, int> p1, const pair<int, int> p2)
{
    if (p1.second == p2.second)
        return p1.first <= p2.first;
    return p1.second <= p2.second;
}
class Solution
{
public:
    int bin(int l, int r, int val, vector<pair<int, int>> &vp)
    {
        if (l == r)
        {
            if (vp[l].first < val)
            {
                return l;
            }
        }
        if (l < r)
        {
            int mid = (l + r) / 2;
            if (vp[mid].first < val)
            {
                int right = bin(mid + 1, r, val, vp);
                if (right == -1)
                    return mid;
                return right;
            }
            else
            {
                return bin(l, mid - 1, val, vp);
            }
        }
        return -1;
    }
    int minLaptops(int N, int start[], int end[])
    {
        // code here
        map<int, int> m;

        vector<pair<int, int>> vp;
        for (int i = 0; i < N; i++)
        {
            vp.push_back({start[i], end[i]});
        }
        sort(vp.begin(), vp.end());
        vector<int> cnt(N, 0);
        for (int i = 0; i < N; i++)
        {
            int j = bin(i + 1, N - 1, vp[i].second, vp);
            cnt[i] = max(1, j - i + 1);
        }
        int maxi = *max_element(cnt.begin(), cnt.end());
        for (int i = 0; i < N; i++)
        {
            // cout << vp[i].first << " " << vp[i].second << " " << cnt[i] << endl;
        }
        int k = 1;
        vector<int> status(N);
        for (int i = 0; i < N; i++)
        {
            if (status[i] != 0)
                continue;
            else
            {
                int j = i;
                while (j < N)
                {
                    // cout << j << " " << k << endl;
                    if (status[j] == 0)
                    {
                        status[j] = k;
                        j += cnt[j];
                    }
                    else
                    {
                        j++;
                    }
                }
                // if (j < N - 1)
                    k++;
            }
        }
        maxi=*max_element(status.begin(), status.end());
        return max(1, maxi);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int start[N], end[N];
    for (int i = 0; i < N; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> end[i];
    }
    Solution ob;
    cout << ob.minLaptops(N, start, end) << endl;
    return 0;
}