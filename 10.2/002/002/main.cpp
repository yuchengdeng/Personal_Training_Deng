#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxm 8010
#define top1 100
#define top2 100
#define top3 8000
const unsigned short pis[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
const unsigned short pis2[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};
const unsigned short pip[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15};
unsigned short x[maxm], y[maxm], xx, yy;
int cnt1[16][16], cnt2[16][16], cnt3[16][16], n;
unsigned char y_1, y_2, y_3, y_4, v_1, v_2, v_3, v_4, u_1, u_2, u_3, u_4;
bool x05, x07, x08, u06, y08, y14, y16, u08, u14, u16;
bool x01, x02, x04, x09, x10, x12, y01, y03, y05, y06, y07, y09, y11, y13, y15, u01, u03, u05, u07, u09, u11, u13, u15;
unsigned short key24 [260], key13[260];
unsigned char key1, key2, key3, key4;
unsigned int key;
bool flag;
unsigned short kr, u, v, uv[65536], vu[65536], vw[65536];
void prework()
{
    unsigned short upr2, vpr2, wpr2;
    for(unsigned int upr = 0; upr <= 65535; upr++)
    {
        vpr2 = 0;
        upr2 = upr;
        for(unsigned short i = 0; i <= 3; i++)
        {
            vpr2 |= ((pis[upr2&0x000f]) << (i<<2));
            upr2 = upr2 >> 4;
        }
        uv[upr] = vpr2; vu[vpr2] = upr;
    }
    for(unsigned int vpr = 0; vpr <= 65535; vpr++)
    {
        vpr2 = vpr;
        wpr2 = 0;
        for(int i = 0; i < 16; i++)
        {
            wpr2 |= (vpr2 & 0x1) << pip[i];
            vpr2 = vpr2 >> 1;
        }
        vw[vpr] = wpr2;
    }
}
void read()
{
    char c;
    for(int i = 0; i < 8000; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            x[i] = x[i] << 4;
            c = getchar();
            x[i] |= (c>=97 ? c-'a'+10 : c-'0');
        }
        c = getchar();
        for(int j = 1; j <= 4; j++)
        {
            y[i] = y[i] << 4;
            c = getchar();
            y[i] |= (c>=97 ? c-'a'+10 : c-'0');
        }
        c = getchar();
    }
}
bool cmp1(unsigned short x, unsigned short y)
{
    unsigned short xa = x >> 4, xb = (x << 4) >> 8, ya = y >> 4, yb = (y << 4) >> 8;
    return cnt1[xa][xb] > cnt1[ya][yb];
}
bool cmp2(unsigned short x, unsigned short y)
{
    unsigned short xa = x >> 4, xb = (x << 4) >> 8, ya = y >> 4, yb = (y << 4) >> 8;
    return cnt2[xa][xb] > cnt2[ya][yb];
}
unsigned short spn(unsigned short w, unsigned int K)
{
    for(int r = 0; r <= 3; r++)
    {
        kr = K >> (16 - (r<<2));
        u = w ^ kr;
        v = uv[u];
        if(r < 3)
        {
            w = vw[v];
        }
        else
        {
            kr = K;
            w = v ^ kr;
        }
    }
    return w;
}
int main()
{
    freopen("t.txt","r", stdin);
    freopen("q.txt","w", stdout);
    prework();
    scanf("%d\n", &n);
    for(int g = 0; g < n; g++)
    {
        memset(x, 0,sizeof(x));
        memset(y, 0,sizeof(y));
        memset(cnt1, 0,sizeof(cnt1));
        read();
        for(int i = 0; i < 8000; i++)
        {
            xx = x[i]; yy = y[i];
            xx >>= 8; x08 = (xx & 0x1);
            xx >>= 1; x07 = (xx & 0x1);
            xx >>= 2; x05 = (xx & 0x1);
            /*
            y16 = yy;
            yy >>= 2; y14 = yy;
            yy >>= 6; y08 = yy;
            yy >>= 2; y06 = yy;
            */
            y_4 = yy & 0xf;
            yy >>= 8; y_2 = yy & 0xf;
            for(unsigned char k2 = 0; k2 < 16; k2++)
                for(unsigned char k4 = 0; k4 < 16; k4++)
                {
                    u_2 = pis2[y_2 ^ k2]; u_4 = pis2[y_4 ^ k4];
                    u16 = u_4 & 0x1;
                    u14 = (u_4 >> 2) & 0x1;
                    u08 = u_2;
                    u06 = (u_2 >> 2) & 0x1;
                    if((x05^x07^x08^u06^u08^u14^u16) == 1)
                        cnt1[k2][k4]++;
                }
        }
        for(int k2 = 0; k2 < 16; k2++)
            for(int k4 = 0; k4 < 16; k4++)
            {
                if(cnt1[k2][k4] < 4000)
                    cnt1[k2][k4] = 8000 - cnt1[k2][k4];
            }
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 16; j++)
                printf("%01x %01x %d\n", i, j, cnt1[i][j]);
        for(int i = 0; i < 256; i++) key24[i] = i;
        sort(key24, key24+256, cmp1);
        for(int k24 = 0; k24 < top1; k24++)
        {
            memset(cnt2, 0,sizeof(cnt2));
            memset(cnt3, 0,sizeof(cnt3));
            key2 = key24[k24] >> 4; key4 = key24[k24] & 0xf;
            for(int i = 0; i < 8000; i++)
            {
                xx = x[i]; yy = y[i];
                xx >>= 4; x12 = (xx & 0x1);
                xx >>= 2; x10 = (xx & 0x1);
                xx >>= 1; x09 = (xx & 0x1);
                xx >>= 5; x04 = (xx & 0x1);
                xx >>= 2; x02 = (xx & 0x1);
                xx >>= 1; x01 = (xx & 0x1);
                y_4 = yy & 0xf;
                yy >>= 4; y_3 = yy & 0xf;
                yy >>= 4; y_2 = yy & 0xf;
                yy >>= 4; y_1 = yy & 0xf;
                for(unsigned char k1 = 0; k1 < 16; k1++)
                    for(unsigned char k3 = 0; k3 < 16; k3++)
                    {
                        u_1 = pis2[y_1 ^ k1]; u_2 = pis2[y_2 ^ key2];
                        u_2 = pis2[y_3 ^ k3]; u_4 = pis2[y_4 ^ key4];
                        u15 = (u_4 >> 1) & 0x1;
                        u13 = (u_4 >> 3) & 0x1;
                        u11 = (u_3 >> 1) & 0x1;
                        u09 = (u_3 >> 3) & 0x1;
                        u07 = (u_2 >> 1) & 0x1;
                        u05 = (u_2 >> 3) & 0x1;
                        u03 = (u_1 >> 1) & 0x1;
                        u01 = (u_1 >> 3) & 0x1;
                        if((x01^x02^x04^u01^u05^u09^u13) == 1)
                            cnt2[k1][k3] ++;
                        if((x09^x10^x12^u03^u07^u11^u15) == 1)
                            cnt3[k1][k3]++;
                    }
            }
            for(int k1 = 0; k1 < 16; k1++)
                for(int k3 = 0; k3 < 16; k3++)
                {
                    if(cnt2[k1][k3] <4000) cnt2[k1][k3] = 8000 - cnt2[k1][k3];
                    if(cnt3[k1][k3] <4000) cnt3[k1][k3] = 8000 - cnt3[k1][k3];
                    cnt2[k1][k3] += cnt3[k1][k3];
                }
            for(int i = 0; i < 256; i++) key13[i] = i;
            sort(key13, key13+256, cmp2);

            for(int k13 = 0; k13 < top2; k13++)
            {
                key1 = key13[k13] >> 4; key3 = key13[k13] & 0xf;
                key = (key1<<12)|(key2<<8)|(key3<<4)|key4;
                for(unsigned int key0 = 0; key0 < 65536 ; key0++)
                {
                    key |= (key0 << 16);
                    flag = 0;
                    for(int i = 0; i < top3; i++)
                    {
                        if (y[i] != spn(x[i], key))
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        printf("%08x", key);
    }
    return 0;
}
