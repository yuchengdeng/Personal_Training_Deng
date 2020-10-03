//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxm 8010
#define top1 13
#define top2 2
#define top3 2
const unsigned char pis[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
const unsigned char pis2[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};
const unsigned short pip[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15};
unsigned short x[maxm], y[maxm], xx, yy;
unsigned short cnt1[16][16], cnt2[16][16], cnt3[16][16];
int n, ii;
unsigned char y_1, y_2, y_3, y_4, v_1, v_2, v_3, v_4, u_1, u_2, u_3, u_4;
unsigned char x05, x07, x08, u06, y08, y14, y16, u08, u14, u16;
unsigned char x01, x02, x04, x09, x10, x12, y01, y03, y05, y06, y07, y09, y11, y13, y15, u01, u03, u05, u07, u09, u11, u13, u15;
unsigned char key1, key2, key3, key4;
unsigned int key, key1234;
bool flag;
unsigned short kr, u, v, uv[65536], vu[65536], vw[65536], cntp;
struct keynode
{
    unsigned char x, y;
    unsigned short cnt;
} key24[260], key13[260];
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
bool cmp(keynode x, keynode y)
{
    return x.cnt > y.cnt;
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
    //freopen("t.txt","r", stdin);
    //freopen("q.txt","w", stdout);
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
            xx >>= 8; x08 = xx;
            xx >>= 1; x07 = xx;
            xx >>= 2; x05 = xx;
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
                    u16 = u_4;
                    u14 = u_4 >> 2;
                    u08 = u_2;
                    u06 = u_2 >> 2;
                    if(((x05^x07^x08^u06^u08^u14^u16)&0x1) == 0)
                        cnt1[k2][k4]++;
                }
        }
        for(unsigned char k2 = 0; k2 < 16; k2++)
            for(unsigned char k4 = 0; k4 < 16; k4++)
            {
                ii = (k2<<4)|k4; cntp = cnt1[k2][k4];
                if(cntp < 4000) cntp = 8000-cntp;
                key24[ii] = {k2, k4, cntp};
            }
        /*for(int i = 0; i < 16; i++)
            for(int j = 0; j < 16; j++)
                printf("%01x %01x %d\n", i, j, cnt1[i][j]);
        printf("\n");*/
        sort(key24, key24+256, cmp);

        for(int k24 = 0; k24 < top1; k24++)
        {
            memset(cnt2, 0,sizeof(cnt2));
            memset(cnt3, 0,sizeof(cnt3));
            key2 = key24[k24].x; key4 = key24[k24].y;
            //printf("\n\n%01x %01x %d\n\n", key2, key4, cnt1[key2][key4]);
            for(int i = 0; i < 8000; i++)
            {
                xx = x[i]; yy = y[i];
                xx >>= 4; x12 = xx;
                xx >>= 2; x10 = xx;
                xx >>= 1; x09 = xx;
                xx >>= 5; x04 = xx;
                xx >>= 2; x02 = xx;
                xx >>= 1; x01 = xx;
                y_4 = yy & 0xf;
                yy >>= 4; y_3 = yy & 0xf;
                yy >>= 4; y_2 = yy & 0xf;
                yy >>= 4; y_1 = yy & 0xf;
                u_2 = pis2[y_2 ^ key2];
                u_4 = pis2[y_4 ^ key4];
                u15 = u_4 >> 1;
                u13 = u15 >> 2;
                u07 = u_2 >> 1;
                u05 = u07 >> 2;
                for(unsigned char k1 = 0; k1 < 16; k1++)
                    for(unsigned char k3 = 0; k3 < 16; k3++)
                    {
                        u_1 = pis2[y_1 ^ k1];
                        u_3 = pis2[y_3 ^ k3];
                        u11 = u_3 >> 1;
                        u09 = u11 >> 2;
                        u03 = u_1 >> 1;
                        u01 = u03 >> 2;
                        if(((x01^x02^x04^u01^u05^u09^u13)&0x1) == 0)
                            cnt2[k1][k3] ++;
                        if(((x09^x10^x12^u03^u07^u11^u15)&0x1) == 0)
                            cnt3[k1][k3]++;
                    }
            }
            for(unsigned char k1 = 0; k1 < 16; k1++)
                for(unsigned char k3 = 0; k3 < 16; k3++)
                {
                    ii = (k1<<4)|k3; cntp = cnt2[k1][k3];
                    if(cntp < 4000) cntp = 8000-cntp;
                    key13[ii] = {k1, k3, cntp};
                    cntp = cnt3[k1][k3];
                    if(cntp < 4000) cntp = 8000-cntp;
                    key13[ii].cnt += cntp;
                }
            sort(key13, key13+256, cmp);

            for(int k13 = 0; k13 < top2; k13++)
            {
                key1 = key13[k13].x; key3 = key13[k13].y;
                //printf("%01x %01x %d\n", key1, key3, cnt2[key1][key3]);
                key1234 = key1;
                key1234 <<= 4; key1234 |= key2;
                key1234 <<= 4; key1234 |= key3;
                key1234 <<= 4; key1234 |= key4;
                for(unsigned int key0 = 0; key0 < 65536 ; key0++)
                {

                    key = key1234|(key0 << 16);
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
        printf("%08x\n", key);
    }
    return 0;
}
