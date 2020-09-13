#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void get_nxt(char *a, int *nxt) {
    int i , j, n = strlen(a);
    for(j = nxt[0] = -1, i = 1; i <= n; nxt[i++] = j) {
        while(j>-1 && a[j+1]!=a[i]) j = nxt[j];
        if(a[j+1] == a[i]) j++;
    }
}

int op(int x, int y) {
    printf("%d\n", x-y+2);
    return 1;
}
int kmp(char *a, int *nxt, char *b) {
    int ans, i, j, n = strlen(a), m = strlen(b);
    for(j = -1, i = 0; i < m; i++) {
        while(j>-1 && a[j+1]!=b[i]) j = nxt[j];
        if(a[j+1] == b[i]) j++;
          if(j == n-1) ans+=op(i, n), j = nxt[j]; 
    }
    return ans;
}

#define maxn 1000010
char s1[maxn], s2[maxn];
int nxt[maxn];
int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    get_nxt(s2, nxt);
    kmp(s2, nxt, s1);
    int m = strlen(s2);
    for(int i = 0; i < m; i++) printf("%d ", nxt[i]+1);
    return 0;
}