#include <iostream>
#include <cstdio>
using namespace std;
#define maxm 8010
#define top1 100
#define top2 100
#define top3 8000
const unsigned short pis[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
const unsigned short pis2[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};
const unsigned short pip[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15};
unsigned short x[maxm], y[maxm], xx, yy;
int cnt1[16][16], cnt2[16][16], cnt3[16][16];
bool x05, x07, x08, u06, y08, y14, y16, u08, u14, u16;
bool x01, x02, x04, x09, x10, x12, y01, y03, y05, y07, y09, y11, y13, y15, u01, u03, u05, u07, u09, u11, u13, u15;
unsigned short key24 [260], key13[260], key1, key2, key3, key4;
unsigned int key;
bool flag;
unsigned char kr, u, v;

void read()
{
    char c;
    for(int i = 0; i < 8000; i++)
    {
        for(int i = 1; i <= 4; i++)
        {
            x[i] = x[i] << 4;
            c = getchar();
            x[i] |= (c>=97 ? c-'a'+10 : c-'0');
        }
        c = getchar();
        for(int i = 1; i <= 4; i++)
        {
            y[i] = y[i] << 4;
            c = getchar();
            y[i] |= (c>=97 ? c-'a'+10 : c-'0');
        }
        c = getchar();
    }
}
bool cmp(unsigned short x, unsigned short y)
{
    xa = x >> 4; xb = (x << 4) >> 8;
    ya = y >> 4; yb = (y << 4) >> 8;
    return cnt1[xa][ya] > cnt2[xa][ya];
}
unsigned short spn(unsigned short w, unsigned int K)
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
    return w;
}
int main()
{
    prework();
    scanf("%d", &n);
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
            xx = x[i]; yy = y[i];
            x08 = (xx >> 8); x07 = (xx >> 9); x05 = (xx >> 11);
            u16 = yy^k4; u14 = (yy>>2)^(k4>>2);
            u08 = (yy>>8)^k2; u06 = (yy>>10)^(k2>>2);
            */
            y16 = yy; 
            yy >>= 2; y14 = yy; 
            yy >>= 6; y08 = yy;
            yy >>= 2; y06 = yy;
            for(int k2 = 0; k2 < 16; k2++)
                for(int k4 = 0; k4 < 16; k4++)
                {
                    u14 = y14 ^ (k4 >> 2); 
                    u08 = y08 ^ k2;
                    u06 = y06 ^ (k2 >> 2);
                    if(x05^x07^x08^u06^u08^u14^u16 == 1)
                        cnt1[k2][k4]++;   
                }
        }
        for(int k2 = 0; k2 < 16; k2++)
            for(int k4 = 0; k4 < 16; k4++)
            {
                if(cnt1[k2][k4] < 4000)
                    cnt1[k2][k4] = 8000 - cnt1[k2][k4];
            }
        for(int i = 0; i < 256; i++) key24[i] = i;
        sort(key24, key24+256, cmp);       
        
        for(int k24 = 0; k24 <= top1; k24++)
        {
            memset(cnt2, 0,sizeof(cnt2));
            memset(cnt3, 0,sizeof(cnt3));
            key2 = key24[k24] >> 4; key4 = key24[k24] << 8 >> 4;
            for(int i = 0; i < 8000; i++)
            {
                xx = x[i]; yy = y[i];
                xx >>= 4; x12 = xx;
                xx >>= 2; x10 = xx;
                xx >>= 1; x09 = xx;
                xx >>= 5; x04 = xx;
                xx >>= 2; x02 = xx;
                xx >>= 1; x01 = xx;
                yy >>= 1; y15 = yy;
                yy >>= 2; y13 = yy;
                yy >>= 2; y11 = yy;
                yy >>= 2; y09 = yy;
                yy >>= 2; y07 = yy;
                yy >>= 2; y05 = yy;
                yy >>= 2; y03 = yy;
                yy >>= 2; y01 = yy;
                for(int k1 = 0; k1 < 16; k1++)
                    for(int k3 = 0; k3 < 16; k3++)
                    {
                        u15 = y15^(key4 >> 1);
                        u13 = y13^(key4 >> 3);
                        u11 = y11^(k3 >> 1);
                        u09 = y09^(k3 >> 3);
                        u07 = y07^(key2 >> 1);
                        u05 = y05^(key2 >> 3);
                        u03 = y03^(k1 >> 1);
                        u01 = y01^(k1 >> 3);
                        if(x01^x02^x04^u01^u05^u09^u13 == 1)
                            cnt2[k1][k3] ++;
                        if(x09^x10^x12^u03^u07^u11^u15 == 1)
                            cnt3[k1][k3]++;                 
                    }    
            }
            for(int k1 - 0; k1 < 16; k1++)
                for(int k3 = 0; k3 < 16; k3++)
                {
                    if(cnt2[k1][k3] <4000) cnt2[k1][k3] = 8000 - cnt2[k1][k3];
                    if(cnt3[k1][k3] <4000) cnt3[k1][k3] = 8000 - cnt3[k1][k3];
                    cnt2[k1][k3] += cnt3[k1][k3];
                }
            for(int i = 0; i < 256; i++) key13[i] = i;
            sort(key13, key13+256, cmp);
            
            for(int k13 = 0; k13 <= top2; k13++)
            {
                key1 = key13[k13] >> 4; key3 = key13 << 8 >> 4;
                key = (key1<<12)|(key2<<8)||(key3<<4)||key4;
                for(unsigned int key0 = 0; key0 < 65536 ; key0++)
                {
                    key |= (key0 << 16);
                    flag = 0;
                    for(int i = 0; i <= top3; i++)
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