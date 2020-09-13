#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 110
int n, m;
int e[maxn*maxn], nexte[maxn*maxn], mape[maxn], cnt;
int ind[maxn];
//int a[maxn], l, r;
int topsort() {
    /*int nowp,   cnt = 0;
    l = 0;  r = -1;
    for (int i = 0; i < n; i++) if (!ind[i]) a[++r] = i;
    while (l <= r) {
        nowp = a[l];
        cnt++;
        for (int i = 0; i < n; i++)
            if  (e[nowp][i]) {
                ind[i]--;
                if (!ind[i]) a[++r] = i;
            }
        l++;
    }
    if(cnt != n) return 0;
    return 1;
    */
    queue<int> Q;
    int sum=0;
    for(int i=0;i<n;i++)if(ind[i]==0)
        Q.push(i);
    while(!Q.empty()) {
        int u=Q.front(); Q.pop();
        sum++;
        for(int i=mape[u]; i!=0; i=nexte[i]) {
            if(--ind[e[i]]==0) Q.push(e[i]);
        }
    }
    return sum==n;
}
void add_edge(int u, int v) {
    e[++cnt] = v;
    nexte[cnt] = mape[u];
    mape[u] = cnt;
}
int main()
{
    /*while(scanf("%d%d",&n,&m)==2&&n)
    {
        memset(ind ,0,sizeof(ind));
        memset(e, 0, sizeof(mape));
        for(int i=0; i < m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u][v] = 1;
            ind[v]++;
        }
        printf("%s\n",topsort()? "YES" : "NO");
    }*/
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        memset(ind, 0, sizeof(ind));
        memset(mape, 0, sizeof(mape));
        cnt = 0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u, v);
            ind[v]++;
        }
        printf("%s\n",topsort()?"YES":"NO");
    }
    return 0;
}