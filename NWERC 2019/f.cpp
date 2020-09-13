#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 200000
struct A {
    int mem, num;
} a[maxn+50];
int n, m, v, cnt, last, cnt2, fa[maxn+50], ans[maxn+50][3];
bool cmp1(A x, A y) {
    return x.num < y.num;
}
int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx!= fy) fa[fx] = fy;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 1; j <= m; j++) {
            scanf("%d", &v);
            a[++cnt].mem = i;
            a[cnt].num = v;
        }
    }
    sort(a+1, a+cnt+1, cmp1);
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = 1; i <= cnt; i++) {
        if(a[i].num != a[i-1].num) last = i;
        if(find(a[i].mem)!= find(a[last].mem)) {
            ans[++cnt2][0] = a[last].mem; ans[cnt2][1] = a[i].mem; ans[cnt2][2] = a[i].num;
            merge(a[i].mem, a[last].mem);
        }
    }
    if(cnt2 != n-1) printf("impossible\n");
    else {
        for(int i = 1; i <= n-1; i++)
            printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    
    return 0;
}
