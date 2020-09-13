#include <iostream>
#include <cstdio>
using namespace std;
const unsigned short pis[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
const unsigned short pis2[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};
const unsigned short pip[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15};
unsigned short w, u, v, ww, kr;
unsigned int K;
int n;
void read()
{
    char c;
    K = 0;
    for(int i = 1; i <= 8; i++)
    {
        K = K << 4;
        c = getchar();
        K |= (c>=97 ? c-'a'+10 : c-'0');
    }
    c = getchar();
    w = 0;
    for(int i = 1; i <= 4; i++)
    {
        w = w << 4;
        c = getchar();
        w |= (c>=97 ? c-'a'+10 : c-'0');
    }
    c = getchar();
}

void work1()
{
    for(int r = 0; r <= 3; r++)
    {
        kr = K >> (16 - (r<<2));
        u = w ^ kr;
        v = 0;
        for(int i = 0; i <= 3; i++)
        {
            v |= (pis[u&0x000f]) << (i<<2);
            u = u >> 4;
        }
        w = 0;
        if(r < 3)
        {
            for(int i = 0; i < 16; i++)
            {
                w |= (v & 0x1) << pip[i]; //这里是因为pip置换是对称的。
                v = v >> 1;
            }
        }
        else
        {
            kr = K;
            w = v ^ kr;
        }
    }
    printf("%04x", w);
}
void work2()
{
    w  = w ^ 0x1;
    for(int r = 3; r >= 0; r--)
    {
        v  = 0;
        if(r < 3)
        {
            for(int i = 0; i < 16; i++)
            {
                v |= (w & 0x1) << pip[i];
                w = w >> 1;
            }
        }
        else
        {
            kr = K;
            v = w ^ kr;
        }
        u = 0;
        for(int i = 0; i <= 3; i++)
        {
            u |= (pis2[v&0x000f]) << (i<<2);
            v = v >> 4;
        }
        kr = K >> (16 - (r << 2));
        w = u ^ kr;
    }
    printf(" %04x", w);
}
int main()
{
    scanf("%d\n", &n);
    for(int i = 1; i <= n; i++)
    {
        read();
        work1();
        work2();
        if(i < n)
            printf("\n");
    }
    return 0;
}
/*
2
fa94d63f 26b7
3a94d63f 26b7
*/