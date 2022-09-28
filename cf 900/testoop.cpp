#include <iostream>
#include <string>
using namespace std;
class Base
{
public:
    void func_f1(int i) { cout << "In base func_f1 "; }
    void func_f2(int i) { cout << "In base func_f2 "; }
};
class Derived : public Base
{
public:
    void func_f1(int i)
    {
        cout << "In derived func_f1 ";
    }
    void func_f1(string s) { cout << "func_f1 string "; }
    void func_f3(int i) { cout << "In derived func_f3 "; }
};
int main()
{
    Base b;
    Derived d;
    d.func_f1(3);
    d.func_f1("Blue");
    d.func_f3(3);
    d.func_f2(3);
    return 0;
}