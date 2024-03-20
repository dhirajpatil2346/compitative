#include <iostream>
#include <vector>
#include <algorithm>
using LL = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LL rows;
    cin >> rows;

    vector<vector<char>> theater(rows, vector<char>());
    vector<LL> groups;
    vector<LL> seatCost;
    LL totalCollection;

    for (int i = 0; i < rows; ++i)
    {
        string row;
        cin >> row;
        theater[i] = vector<char>(row.begin(), row.end());
    }

    string groupsStr;
    cin >> groupsStr;
    int pos = 0;

    while (pos < (int)groupsStr.length())
    {
        if (groupsStr[pos] == ',')
        {
            pos++;
            continue;
        }
        LL num = 0;
        while (pos < (int)groupsStr.length() && groupsStr[pos] != ',')
        {
            num *= 10ll;
            num += (groupsStr[pos] - '0');
            pos++;
        }
        groups.push_back(num);
    }

    int toFind = 0;

    for (int i = 0; i < rows; ++i)
    {
        string cost;
        cin >> cost;
        if (cost == "?")
        {
            toFind = i;
            seatCost.push_back(0);
        }
        else
            seatCost.push_back(stoi(cost));
    }

    cin >> totalCollection;

    int groupIndex = 1;
    vector<int> notAssignedGroups;

    for (int i = (int)groups.size() / 2; i < (int)groups.size(); i++, groupIndex++)
    {
        bool done = false;
        for (int j = 0; j < rows; j++)
        {
            int availableSeats = count(theater[j].begin(), theater[j].end(), '_');
            if (availableSeats >= groups[i])
            {
                for (auto &seat : theater[j])
                {
                    if (seat == '_' && groups[i] > 0)
                    {
                        char groupChar = '0' + groupIndex;
                        seat = groupChar;
                        groups[i]--;
                    }
                }
                done = true;
                break;
            }
        }
        if (!done)
        {
            notAssignedGroups.push_back(groupIndex);
        }
    }

    for (int i = 0; i < (int)groups.size() / 2; i++, groupIndex++)
    {
        bool done = false;
        for (int j = 0; j < rows; j++)
        {
            int availableSeats = count(theater[j].begin(), theater[j].end(), '_');
            if (availableSeats >= groups[i])
            {
                for (auto &seat : theater[j])
                {
                    if (seat == '_' && groups[i] > 0)
                    {
                        char groupChar = '0' + groupIndex;
                        seat = groupChar;
                        groups[i]--;
                    }
                }
                done = true;
                break;
            }
        }
        if (!done)
        {
            notAssignedGroups.push_back(groupIndex);
        }
    }

    int emptySeatCount = 0;

    for (auto &row : theater)
    {
        for (auto &seat : row)
        {
            cout << seat;
            if (seat == '_')
                emptySeatCount++;
        }
        cout << endl;
    }

    cout << emptySeatCount << " ";

    for (auto &group : notAssignedGroups)
        cout << group << " ";

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        if (i == toFind)
            continue;
        for (auto &seat : theater[i])
        {
            if (seat != '_' && seat != 'X')
            {
                totalCollection -= seatCost[i];
            }
        }
    }

    long double averageCost = 0;
    long double one = 1;

    for (auto &seat : theater[toFind])
    {
        if (seat != '_' && seat != 'X')
            averageCost += one;
    }

    cout << (LL)(totalCollection / averageCost) << endl;

    return 0;
}
