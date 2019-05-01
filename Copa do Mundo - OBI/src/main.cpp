#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> teams;

    for (char i = 'A'; i <= 'P'; i++)
        teams.push(i);

    for (char i = 0; i < 15; i++)
    {
        short int in, in2;
        cin >> in >> in2;
        if (in > in2)
        {
            teams.push(teams.front());
            teams.pop();
            teams.pop();
        }
        else
        {
            teams.pop();
            teams.push(teams.front());
            teams.pop();
        }
    }

    cout << teams.front() << endl;

    return 0;
}