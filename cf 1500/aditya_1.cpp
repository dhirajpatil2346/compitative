// Program to find the amount of water in j-th glass
// of i-th row
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the amount of water in jth glass of ith row
float findWater(int i, int j, float X)
{

    float glass[i * (i + 1) / 2];

    memset(glass, 0, sizeof(glass));
    int index = 0;
    glass[index] = X;

    for (int row = 1; row <= i; ++row)
    {
        for (int col = 1; col <= row; ++col, ++index)
        {
            X = glass[index];

            glass[index] = (X >= 1.0f) ? 1.0f : X;

            X = (X >= 1.0f) ? (X - 1) : 0.0f;

            glass[index + row] += X / 2;
            glass[index + row + 1] += X / 2;
        }
    }

    return glass[i * (i - 1) / 2 + j - 1];
}

// Driver program to test above function
int main()
{
    int i = 2, j = 2;
    float X = 2.0; // Total amount of water

    printf("Amount of water in jth glass of ith row is: %f",
           findWater(i, j, X));

    return 0;
}
