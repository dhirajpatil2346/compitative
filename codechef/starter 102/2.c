#include <stdio.h>
struct
{
    int x;
    float y;
} decl;
int main()
{
    int i = 5;
    switch (i)
    {
    default:
        i = 4;
    case 6:
        i--;
    case 5:
        i = i + 1;
    case 1:
        i = i - 1;
    }
    printf("%d \n", i);
    return 0;
}