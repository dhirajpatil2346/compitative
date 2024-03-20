#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
class Solution
{
public:
    bool check(unordered_map<char, int>& m, int k)
    {
        for (auto &val : m)
            if (val.second != k)
                return false;
        return true;
    }
    int countCompleteSubstrings(string s, int k)
    {
        int n = s.length(), cnt = 0;
        for (int p = 1; p <= 26; p++)
        {
            unordered_map<char, int> m;
            int window = p * k;
            if (window > s.length())
                break;
            m[s[0]]++;
            set<int> faulty;
            for (int i = 1; i < window; i++)
            {
                if (abs(s[i] - s[i - 1]) > 2)
                    faulty.insert(i);
                m[s[i]]++;
            }
            // cout << p << " " << faulty.size() << " " << m.size() << endl;
            if (faulty.size() == 0 && (check(m, k)))
                cnt++;
            for (int j = 0, i = window; i < n; i++, j++)
            {
                // cout << p << " " << endl;
                if (faulty.find(j+1) != faulty.end())
                    faulty.erase(faulty.find(j+1));
                if (faulty.find(j) != faulty.end())
                    faulty.erase(faulty.find(j));
                if (abs(s[i] - s[i - 1]) > 2)
                    faulty.insert(i);
                m[s[j]]--;
                if (m[s[j]] == 0)
                    m.erase(s[j]);
                m[s[i]]++;
                if (faulty.size() == 0 && ((check(m, k))))
                    cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    string s;
    cin >> s;
    Solution sc;
    int k;
    cin >> k;
    cout << sc.countCompleteSubstrings(s, k) << endl;
    return 0;
}