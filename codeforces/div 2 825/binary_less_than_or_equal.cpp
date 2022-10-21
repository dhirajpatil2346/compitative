#include <bits/stdc++.h>
using namespace std;
#define ll long long

int search(vector<int> &array, int start_idx, int end_idx, int search_val)
{

    if (start_idx == end_idx)
        return array[start_idx] <= search_val ? start_idx : -1;

    int mid_idx = start_idx + (end_idx - start_idx) / 2;
    if (search_val < array[mid_idx])
    {
        return search(array, start_idx, mid_idx, search_val);
    }
    int ret = search(array, mid_idx + 1, end_idx, search_val);
    return ret == -1 ? mid_idx : ret;
}

int gsearch(vector<int> &array, int start_idx, int end_idx, int search_val)
{

    if (start_idx == end_idx)
        return array[start_idx] <= search_val ? start_idx : -1;

    int mid_idx = start_idx + (end_idx - start_idx) / 2;
    if (array[mid_idx] > search_val)
    {
        return gsearch(array, start_idx, mid_idx, search_val);
    }
    int ret = gsearch(array, mid_idx + 1, end_idx, search_val);
    return ret == -1 ? mid_idx : ret;
}

int main()
{
    vector<int> v = {1, 3, 5, 8, 10, 11, 12};
    cout << search(v, 0, v.size() - 1, 7) << endl;
    return 0;
}