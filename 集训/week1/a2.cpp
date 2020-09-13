#include    <iostream>
#include    <cstdio>
#include    <algorithm>
#include    <cstring>
using   namespace   std;
#define maxn    30
int n,  m,  ans;
int ind[maxn];
char s[maxn];
bool    e[26][26];
int a[maxn],    l,  r;
int topsort() {
    int nowp,   cnt = 0,    x = 0;
    int indcpy[maxn];
    memcpy(indcpy, ind, sizeof(indcpy));
    l = 0;  r = -1;
    for (int i = 0; i < n;  i++) 
        if  (!indcpy[i])   a[++r] = i;
    while   (l <= r)    {
        nowp = a[l];
        s[cnt++] = nowp + 'A';
        if  (l != r)    x = 1;
        for (int i = 0; i < n; i++)
            if  (e[nowp][i])   {
                indcpy[i]--;
                if  (!indcpy[i])   a[++r] = i;
            }
        l++;
    }
    s[cnt] = 0;
    if(cnt < n) x = -1;
    return x;
}
int main() {
    char c1, c2;
    while(scanf("%d%d\n", &n, &m), n||m) {
        memset(ind, 0, sizeof(ind));
        memset(e, 0, sizeof(e));
        ans = 1;
        for(int i = 1; i <= m; i++) {
            scanf("%c<%c\n", &c1, &c2);
            if(ans != 1) continue;
            e[c1-'A'][c2-'A'] = 1;
            ind[c2-'A']++;
            ans = topsort();
            if(ans == 0)
                printf("Sorted sequence determined after %d relations: %s.\n", i, s);
            if(ans == -1)
                printf("Inconsistency found after %d relations.\n", i);
        }
        if(ans == 1)
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
