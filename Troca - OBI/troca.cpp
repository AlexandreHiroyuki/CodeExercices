/*************************************/
/* AutoClick - Automated Mouse Click */
/* Created by Alexandre Hiroyuki     */
/* January 2, 2019                   */
/*************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> faces[2];
    int cards = 0;
    int swaps = 0;

    cin >> cards >> swaps;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < cards; j++)
        {
            int in;
            cin >> in;
            faces[i].push_back(in);
        }

    vector<bool> swapB(cards, false);
    vector<bool> swapE(cards, false);

    for (int i = 0; i < swaps; i++)
    {
        int in;
        cin >> in;
        if (swapB[in - 1])
            swapB[in - 1] = false;
        else
            swapB[in - 1] = true;

        int in2;
        cin >> in2;
        if (swapE[in2 - 1])
            swapE[in2 - 1] = false;
        else
            swapE[in2 - 1] = true;
    }

    int flag = 0;
    for (int i = 0; i < cards; i++)
    {
        if (swapB[i])
        {
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        }

        cout << faces[flag][i] << " ";

        if (swapE[i])
        {
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        }
    }

    return 0;
}
