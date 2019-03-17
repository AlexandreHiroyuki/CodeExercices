#include <iostream>
#include <algorithm>
using namespace std;

bool rooms[1000][1000];
int x_goal, y_goal;
int x_lim, y_lim;

int exitSearch(int steps, int x, int y)
{
    int front = 0;
    int back = 0;
    int right = 0;
    int left = 0;
    if (!rooms[x][y])
        return 0;
    if (x == x_goal && y == y_goal)
        return steps;

    rooms[x][y] = false;

    if ((y + 1) < y_lim)
        front = exitSearch(steps + 1, x, y + 1);
    if ((y - 1) > -1)
        back = exitSearch(steps + 1, x, y - 1);
    if ((x + 1) < x_lim)
        right = exitSearch(steps + 1, x + 1, y);
    if ((x - 1) > -1)
        left = exitSearch(steps + 1, x - 1, y);

    return max(max(front, back), max(right, left));
}

int main()
{
    int x_init, y_init;
    cin >> x_lim >> y_lim;

    for (int i = 0; i < x_lim; i++)
        for (int j = 0; j < y_lim; j++)
        {
            short int in;
            cin >> in;
            if (in > 0)
            {
                if (in == 1)
                {
                    rooms[i][j] = true;
                }
                else if (in == 2)
                {
                    rooms[i][j] = true;
                    x_init = i;
                    y_init = j;
                }
                else
                {
                    rooms[i][j] = true;
                    x_goal = i;
                    y_goal = j;
                }
            }
            else
            {
                rooms[i][j] = false;
            }
        }

    cout << exitSearch(1, x_init, y_init);

    return 0;
}