#include <iostream>
#include <map>
using namespace std;

int isValidPosition(int x, int y, int n)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
    {
        return 1;
    }
    return 0;
}

int squaresInGivenDirection(int x, int y, int n, int xIncrement, int yIncrement, map<pair<int, int>, int> obstacles)
{
    int count = 0;
    pair<int, int> p(x, y); // pair -> current position of the queen

    // while the current position is valid i.e withing board and there is no obstacle -> obstacles[p]=1 if there is an obstacle at position p
    while (isValidPosition(x, y, n) && !obstacles[{x, y}])
    {
        count++;
        x += xIncrement;
        y += yIncrement;
    }
    return count;
}

// x,y -> position of the queen
int queenMoves(int n, int k, int x, int y, int obstaclesX[], int obstaclesY[])
{
    map<pair<int, int>, int> obstacles; // map to store the obstacles
    for (int i = 0; i < k; i++)
    {
        obstacles[make_pair(obstaclesX[i], obstaclesY[i])] = 1;
    }

    int count = 0;
    // 8 directions
    int xIncrement[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int yIncrement[] = {1, -1, 0, 0, 1, -1, -1, 1};

    for (int i = 0; i < 8; i++)
    {
        count += squaresInGivenDirection(x + xIncrement[i], y + yIncrement[i], n, xIncrement[i], yIncrement[i], obstacles);
    }
    return count;
}

int main()
{
    int n = 8, k = 1, x = 4, y = 4;
    int obstaclesX[] = {5};
    int obstaclesY[] = {3};
    cout << queenMoves(n, k, x, y, obstaclesX, obstaclesY);
    return 0;
}