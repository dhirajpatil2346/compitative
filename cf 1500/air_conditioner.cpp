#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(int n, int k, vector<long long> &track, set<pair<long long, int>> &s)
{

    while (s.size())
    {
        auto f = *s.begin();
        s.erase(s.begin());
        int pt = f.second;
        long long temp = f.first;
        if (track[pt] != temp)
            continue;
        for (long long i = pt - 1, curr = temp + 1; i >= 0; i--, curr++)
        {
            if (track[i] <= curr)
                break;
            track[i] = curr;
        }
        for (long long i = pt + 1, curr = temp + 1; i <= n; i++, curr++)
        {
            if (track[i] <= curr)
                break;
            track[i] = curr;
        }
    }
    vector<long long> nt;
    for (int i = 1; i < track.size(); i++)
        nt.push_back(track[i]);
    track = nt;
    return track;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> pos(k), temp(k);
        for (auto &val : pos)
            cin >> val;
        for (auto &val : temp)
            cin >> val;
        vector<long long> track(n + 1, 1e16);
        set<pair<long long, int>> s;
        for (int i = 0; i < k; i++)
        {
            s.insert({temp[i], pos[i]});
            track[pos[i]] = temp[i];
        }
        // for (auto &val : track)
        //     cout << val << " ";
        // cout << endl;
        track = solve(n, k, track, s);
        for (auto &val : track)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}