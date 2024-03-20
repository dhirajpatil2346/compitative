#include <bits/stdc++.h>
using namespace std;
class Trial
{
public:
    Trial()
    {
        cout << "constructinhg " << endl;
    }
    ~Trial()
    {
        cout << "destr" << endl;
    }
};
int getvalue();
int main()
{
     int *ptr;
    int **ptr1;
    int **ptr2;
    ptr = (int *)malloc(sizeof(int));
    ptr1 = (int **)malloc(10* sizeof(int*));
    ptr2 = (int **)malloc(10* sizeof(int*));
    free(ptr);
    free(ptr1);
    free(ptr2);
    return 0;
}
int getvalue()
{
    return 5;
}