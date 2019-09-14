#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned> v;

void mergeSort(unsigned f_index, unsigned l_index)
{
    if (f_index < l_index)
    {
        unsigned middle = (f_index + l_index) / 2;

        mergeSort(f_index, middle);
        mergeSort(middle + 1, l_index);

        unsigned index1 = f_index, index2 = middle + 1;

        if (v[index1] <)
        {
            /* code */
        }
    }
}

int main()
{
    unsigned dancers;
    cin >> dancers;

    for (unsigned i = 0; i < dancers; i++)
    {
        unsigned in;
        cin >> in;
        v.push_back(in);
    }

    return 0;
}