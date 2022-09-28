#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int h = 0; h < n; h++)
    {
        long long int z, x;
        cin >> z >> x;
        long long int count = 0;
        int y = 1;
            for (int j = 1; j < x;)
            {
                y += j;
                j=j*2;
                count++;
            }
            for (; y < z;)
            {
                count++;
                y = y + x;
            }
            cout << count << endl<<endl;
        }
    
    return 0;
}