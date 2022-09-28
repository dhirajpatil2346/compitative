#include <bits/stdc++.h>
using namespace std;

void display(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

int main()
{
    string s, m;
    cin >> s >> m;
    char arr[s.length()];
    for (size_t i = 0; i < (s.length()); i++)
    {
        if (s[i] == m[i])
        {
            arr[i] = '0';
        }
        else
        {
            arr[i] = '1';
        }
    }
    display(arr, s.length());
    return 0;
}