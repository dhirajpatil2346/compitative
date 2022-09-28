#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    cout<<"The length of string no. 1 is : "<<len1<<endl;
    cout<<"The length of string no. 2 is : "<<len2<<endl;
    if (len1 == 0 || len2 == 0)
    return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        cout<<"This is main loop "<<endl<<endl;
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;
         
        // Go from right to left in num2            
        for (int j=len2-1; j>=0; j--)
        {
            cout<<"This is sub loop "<<endl;
            // Take current digit of second number
            int n2 = num2[j] - '0';
            cout<<"The value of n1 and n2 are : "<<n1<<"    and     "<<n2<<endl;
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            cout<<"The value of sum is "<<sum<<endl;
            // Carry for next iteration
            carry = sum/10;
            cout<<"The value of carry is "<<carry<<endl;
            // Store result
            result[i_n1 + i_n2] = sum % 10;
            cout<<"i_n1 is "<<i_n1<<"   ";
            cout<<"i_n2 is "<<i_n2<<"   ";
            for (int i = 0; i <= i_n1+1; i++)
            {
                cout<<"The value in vector at position of "<<i<<" is : "<<result[i]<<endl;
            }
            i_n2++;
            cout<<"i_n2 after sub incriment is "<<i_n2<<endl;
        }
        
        // store carry in next cell
        if (carry > 0){
            cout<<"The carry left was "<<carry<<endl;
            result[i_n1 + i_n2] += carry;
        }
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
        cout<<"the incremented value of i_n1 after one main loop is "<<i_n1<<endl<<endl;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    string s = "";
     
    while (i >= 0)
        s += to_string(result[i--]);
 
    return s;
}
 
// Driver code
int main()
{
    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
     
    if((str1.at(0) == '-' || str2.at(0) == '-') &&
        (str1.at(0) != '-' || str2.at(0) != '-' ))
        cout<<"-";
 
 
    if(str1.at(0) == '-')
        str1 = str1.substr(1);
   
    if(str2.at(0) == '-')
        str2 = str2.substr(1);
 
    cout << multiply(str1, str2);
    return 0;
}