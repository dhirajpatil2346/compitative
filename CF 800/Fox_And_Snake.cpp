#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = 1, d = 0;
    for (int i = 0; i < a; i++)
    {
        if (i % 2 == 0)
        {
            for (int i = 0; i < b; i++)
            {
                cout << '#';
            }
            swap(c, d);
            cout << endl;
        }
        else
        {
            if (c == 0)
            {
                for (int i = 1; i < b; i++)
                {
                    cout << '.';
                }
                cout << '#' << endl;
            }
            else{
                cout << '#' ;
                for (int i = 1; i < b; i++)
                {
                    cout << '.';
                }
                cout<< endl;
            }
        }
    }

    return 0;
}