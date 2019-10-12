#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    short int teste = 0;
    while (true)
    {
        short int n_station, n_lines;

        cin >> n_station >> n_lines;

        if (n_station == 0 && n_lines == 0)
            break;

        vector<short int> station[100];
        vector<bool> visited(100);

        for (int i = 0; i < n_lines; i++)
        {
            short int in, in2;
            cin >> in >> in2;
            station[in].push_back(in2);
            station[in2].push_back(in);
        }

        stack<short int> pilha;

        
        teste++;
    }
    return 0;
}