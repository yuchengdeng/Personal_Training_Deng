#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 50
#define maxm 2000
int n, m, st;
struct edge {
    int u, v;
} e[maxm];
int deg[maxn], ans[maxm], cnt;
bool vis[maxm];
bool pd() {
    for(int i = 1; i <= n; i++)
        if(deg[i]%2) return 0;
    return 1;
}
void euler(int loc) {
    for(int i = 1; i <= m; i++)
        if(!vis[i] && (e[i].u == loc || e[i].v == loc)) {
            vis[i] = 1;
            euler(e[i].u == loc ? e[i].v : e[i].u);
            ans[++cnt] = i;    
        }
}
void add_edge(int x, int y, int z) {
    e[z].u = x;
    e[z].v = y;
    deg[x]++;
    deg[y]++;
    m++;
    n = max(n, max(x, y));
}
int main() {
    int x, y, z;
    while(scanf("%d%d", &x, &y), x||y) {
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        n = m = cnt = 0;
        st = min(x, y);
        scanf("%d", &z);
        add_edge(x, y, z);
        while(scanf("%d%d", &x, &y), x||y) {
            scanf("%d", &z);
            add_edge(x, y, z);
        }
        if(!pd()) {
            printf("Round trip does not exist.\n");
            continue;    
        }
        euler(st);
        for(int i = m; i > 1; i--) printf("%d ", ans[i]);
        printf("%d\n", ans[1]);
    }
    return 0;
}
