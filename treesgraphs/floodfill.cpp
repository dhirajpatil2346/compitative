#include <bits/stdc++.h>
using namespace std;

#define N 50

void bfs(vector<vector<int>> &image, int i, int j, int init, int color)
{
    int row = image.size();
    int col = image[0].size();
    if (i >= row || i < 0 || j >= col || j < 0)
    {
        return;
    }
    if(image[i][j]!=init){return;}
    image[i][j]=color;
    bfs(image, i+1,j,init,color);
    bfs(image, i-1,j,init,color);
    bfs(image, i,j-1,init,color);
    bfs(image, i,j+1,init,color);
}

int main()
{

    return 0;
}