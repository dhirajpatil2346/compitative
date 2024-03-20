#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve(vector<int> &v, ofstream &output_file)
{
    int n = v.size();
    vector<vector<int>> index(3);
    for (int i = 0; i < n; i++)
        index[v[i]].push_back(i);
    for (auto &val : index)
        val.push_back(n);
    int cst = 0;
    for (int i = 0; i < n;)
    {
        cst++;
        if (v[i] == 0)
        {
            int l = i, r = *upper_bound(index[0].begin(), index[0].end(), i);
            int two = *upper_bound(index[2].begin(), index[2].end(), i);
            if (two < r)
            {
                i = r + 1;
            }
            else if (r == (l + 1))
            {
                i++;
            }
            else
            {
                i = r;
            }
        }
        else
        {
            i = *upper_bound(index[0].begin(), index[0].end(), i) + 1;
        }
    }
    output_file << cst << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    vector<int> b = {3, 3};
    for (int i = 1; i <= 5; i++)
    {
        b.push_back(pow(10, i) / 2);
        b.push_back(pow(10, i));
    }
    for (int i = 0; i < b.size(); i++)
    {
        string s = "input";
        s += to_string(i);
        s += ".txt";
        ofstream MyFile(s);
        int t = b[i];
        // cin >> t;
        MyFile << t;
        MyFile << "\n";
        while (t--)
        {
            MyFile << rand() % 3;
            MyFile << " ";
        }
        MyFile.close();
        string op = "output";
        op += to_string(i);
        op += ".txt";

        ifstream input_file(s);
        if (!input_file)
        {
            cerr << "Error opening input.txt file." << endl;
            return 1;
        }

        int n;
        input_file >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            input_file >> v[i];
        }

        input_file.close();
        ofstream output_file(op);
        if (!output_file)
        {
            cerr << "Error opening output.txt file." << endl;
            return 1;
        }

        solve(v, output_file);

        output_file.close();
    }
    return 0;
}