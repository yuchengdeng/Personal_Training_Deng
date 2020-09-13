#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 200000
int len[maxn+5], n;
int fc[maxn+5], lc[maxn+5];
int f[26][26];
char s[15];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        len[i] = strlen(s);
        fc[i] = s[0]-'a'; lc[i] = s[len[i]-1]-'a';
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++)
            if(f[j][fc[i]] || j == fc[i])
                f[j][lc[i]] = max(f[j][lc[i]], f[j][fc[i]]+ len[i]);
    }
    int ans = 0;
    for(int i = 0; i <= 26; i++) ans = max(ans, f[i][i]);
    printf("%d\n", ans);
    return 0;
}