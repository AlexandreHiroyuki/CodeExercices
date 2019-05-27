#include <cstdio>
using namespace std;

#define MAXN 112345
#define MAXM 1123

unsigned short value;
unsigned short coins;

unsigned short coin[MAXM];
bool table[MAXM][MAXN];

bool isPossible(unsigned short coin_it, unsigned short sum)
{
    if (table[coin_it][sum])
        return false;

    table[coin_it][sum] = true;

    if (sum == value)
        return true;

    if (coin_it > coins || sum > value)
        return false;

    return (isPossible(coin_it + 1, sum + coin[coin_it]) || isPossible(coin_it + 1, sum));
}

int main()
{
    scanf("%hd %hd", &value, &coins);

    for (unsigned short i = 1; i <= coins; i++)
        scanf("%hd", &coin[i]);

    printf("%c\n", isPossible(1, 0) ? 'S' : 'N');

    return 0;
}