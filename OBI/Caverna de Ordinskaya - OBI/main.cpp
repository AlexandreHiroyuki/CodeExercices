/*************************************/
/* Caverna de Ordinskaya - OBI 2016  */
/* Created by Alexandre Hiroyuki     */
/* December 28, 2018                 */
/*************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long int swap(long int n, long int size)
{
    return size - n;
}

long int dist(vector<long int> notes, int dives, long int size)
{
    notes[0] = min(notes[0], swap(notes[0], size));

    for (int i = 1; i < dives; i++)
    {
        long int a = min(notes[i], swap(notes[i], size));
        // int b = min(notes[i], swap(notes[i], size));
        if (a >= notes[i - 1])
        {
            notes[i] = a;
        }
        else
        {
            notes[i] = max(notes[i], swap(notes[i], size));
            if (notes[i] < notes[i - 1])
                return -1;
        }
    }

    long int total = 0;

    for (vector<long int>::iterator it = notes.begin(); it != notes.end(); it++)
    {
        total += *it;
    }

    return total;
}

int main()
{
    vector<long int> notes;
    int dives = 0;
    long int size = 0;

    cin >> dives >> size;

    for (int i = 0; i < dives; i++)
    {
        long int in;
        cin >> in;
        notes.push_back(in);
    }

    cout << dist(notes, dives, size) << endl;

    return 0;
}
