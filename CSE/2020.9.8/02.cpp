#include <iostream>
#include <cstdio>
using namespace std;
#define maxm 8000
const unsigned short pis[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
const unsigned short pis2[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};
const unsigned short pip[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15};
const int MAX1 = 8000, MAX2 = 8000;
bool x[maxm][16], y[maxm][16], keybit[16][4];

void read()
{
    char c;
    int k;
    for(int i = 0; i < 8000; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            c = getchar();
            k = j << 2;
            x[i][--k] = c;
            c >>= 1;
            x[i][--k] = c;
            c >>= 1;
            x[i][--k] = c;
            c >>= 1;
            x[i][--k] = c;
        }
        c = getchar();
        for(int j = 1; j <= 4; j++)
        {
            c = getchar();
            k = j << 2;
            y[i][--k] = c;
            c >>= 1;
            y[i][--k] = c;
            c >>= 1;
            y[i][--k] = c;
            c >>= 1;
            y[i][--k] = c;
        }
        c = getchar();
    }
}
int main()
{
    prework();
    scanf("%d\n", &n);
    fro(int g = 1; g <= n; g++)
    {
        read();
        for(int i = 0; i < 8000; i++)
            for(int k2 = 0; k2 < 16; k++)
                for(int k4 = 0; k4 < 16; k4++)
                {
                    if(x[j][4]^x[j][6]^x[j][7]^pis2[y[j][5]^])
                }
    }
    return 0;
}