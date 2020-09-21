//基于AST的同源性检测
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define maxb 1000000
#define maxd 2
#define MOD1 999999937
#define MOD2 1000000007
struct node
{
    unsigned int hash1, hash2;
    int fa, lv, cld;
};
string s[2][maxb];
int n1, n2;
node p[2][maxb];
void predo()
{
    for(int i = 0; i < maxb; i++) p[0][i].hash1 = p[1][i].hash1 = p[0][i].hash2 = p[1][i].hash2 = 0xffffffff;

}

void make_block()
{

}

unsigned int chash(string t, ll MOD) //对块取hash
{
    unsigned int x;
    for(int i = 0; i < t.size(); i++)
        x = ((ll)x*97 + (ll)i) % MOD;
    return x; 
}

void calc_block2(int g, int i)
{
    if(lv < 2) return;
    unsigned int x = p[g][p[g][i].fa].hash2;
    x = x^p[g][i].hash1;
    p[g][p[g][i].fa].hash2 = x;
}

bool cmp(node x, node y)
{
    return (x.lv < y.lv)||(x.lv == y.lv && x.cld < y.cld)||(x.lv == y.lv && x.cld == y.cld && x.hash1 < y.hash1)||(x.lv ==y.lv && x.cld == y.cld && x.hash1 == y.hash1 && x.hash2 <= y.hash2);
}
int main()
{
    predo();
    make_block();
    for(int i = 1; i <= n1; i++) p[0][i].hash1 = chash(s[0][i]);
    for(int i = 1; i <= n2; i++) p[1][i].hash1 = chash(s[1][i]);
    for(int i = 1; i <= n1; i++) calc_block2(0, i);
    for(int i = 1; i <= n2; i++) calc_block2(1, i);
    sort(p[0]+1, p[0]+n1+1, cmp);
    sort(p[1]+1, p[1]+n2+1, cmp);
    int i = 1; j = 1, cnt = 0; 
    while(i <= n1 && j <= n2 && p[0][i].lv < 2 && p[1][j].lv < 2)
    {
        k = j;
        while((k <= n2 && p[1][k].lv < 2)&&(p[0][i].cld != p[1][k].cld)||(p[0][i].hash1 != p[1][k].hash1)||(p[0][i].hash2 != p[1][k].hash2)) k++;
        if(k <= n2 && p[1][k].lv < 2)
        {
            cnt++; j = k+1;
        }
        i++;
    }
    while(i <= n1 && p[0][i].lv < 2) i++;
    while(j <= n2 && p[1][j].lv < 2) j++;
    printf("1号程序共有%d块，2好程序共有%d块，重合%d块", i-1, j-1, cnt);
    return 0;
}