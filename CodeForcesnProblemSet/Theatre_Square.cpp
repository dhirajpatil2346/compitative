#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
string multi(int num1, int num2)
{
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = s1[i] - '0';
        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = s2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
        {
            result[i_n1 + i_n2] += carry;
        }
        i_n1++;
    }
    int m = result.size() - 1;
    while (m >= 0 && result[m] == 0)
    {
        m--;
    }
    string s = "";
    while (m >= 0)
    {
        s += to_string(result[m--]);
    }
    return s;
}
int main()
{
    int m, n, a;
    cin >> m >> n >> a;
    string s1 = to_string(m);
    string s2 = to_string(m);
    int len1, len2;
    len1= s1.length();
    len2= s2.length();
    int x, y;
    // if ((len1 + len2) > 9)
    // {
        if (m % a == 0 && n % a == 0)
        {
            // cout<<"1"<<endl;
            cout << multi(m / a, n / a);
        }
        else if (m % a == 0 && n % a != 0)
        {
            // cout<<"2"<<endl;
            cout << multi(m/a, (n/a)+1);
            
        }
        else if (m % a != 0 && n % a == 0)
        {
            // cout<<"3"<<endl;
            cout << multi((m / a) + 1, n/a);
        }
        else{
            // cout<<"4"<<endl;
            cout << multi((m/a)+1, (n / a) + 1);
        }
    // }
    // else
    // {
    //     if ((m * n) <= (a * a))
    //     {
    //         cout << 1;
    //     }
    //     else
    //     {
    //         // cout<<"Third"<<endl;
    //         if (m % a == 0)
    //         {
    //             x = m / a;
    //         }
    //         else
    //         {
    //             x = (m / a) + 1;
    //         }
    //         if (n % a == 0)
    //         {
    //             y = n / a;
    //         }
    //         else
    //         {
    //             y = (n / a) + 1;
    //         }
    //         cout << x * y;
    //     }
    // }
    return 0;
}