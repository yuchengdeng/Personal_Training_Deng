#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 105
int n, m;
bool e[maxn][maxn];
int ind[maxn];
int a[maxn], l, r;
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
    while(!Q.empty())
    {
        int u=Q.front(); Q.pop();
        sum++;
        for(int i=0;i<n;i++) if(e[u][i])
        {
            if(--in[i]==0) Q.push(i);
        }
    }
    return sum==n;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        memset(ind ,0,sizeof(ind));
        memset(e, 0, sizeof(e));
        for(int i=0; i < m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u][v] = 1;
            ind[v]++;
        }
        printf("%s\n",topsort()? "YES" : "NO");
    }
    return 0;
}