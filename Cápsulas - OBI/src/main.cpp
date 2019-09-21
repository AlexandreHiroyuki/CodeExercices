/*************************************/
/* Cápsulas - OBI 2018               */
/* Created by Alexandre Hiroyuki     */
/* September 20, 2019                */
/*************************************/
#include <iostream>
#include <vector>
using namespace std;

#define MAX_D 100000000

vector<unsigned long> cicles;

unsigned long findDay(unsigned long b, unsigned long e, unsigned long goal)
{
    unsigned long mid = b + (e - b) / 2;

    unsigned long result = 0;
    for (auto i : cicles)
        result += mid / i;

    if (!(b < e))
        return b;

    if (result < goal)
        return findDay(mid + 1, e, goal);
    else
        return findDay(b, mid, goal);
}

int main()
{
    unsigned long capsules = 0;
    unsigned long goal = 0;

    cin >> capsules >> goal;

    cicles = vector<unsigned long>(capsules);

    for (unsigned long i = 0; i < capsules; i++)
        cin >> cicles[i];

    cout << findDay(0, MAX_D, goal) << endl;

    return 0;
}