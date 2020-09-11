#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int edge[maxn * 2], hed[maxn], nexte[maxn * 2], vist[maxn * 2], d[maxn], cnt, n;
int list[maxn], l, r;
int g[maxn][2];

void read()
{
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    { 
        scanf("%d%d", &u, &v);
    	edge[++cnt] = v;
    	nexte[cnt] = hed[u];
    	hed[u] = cnt;
    	edge[++cnt] = u;
    	nexte[cnt] = hed[v];
    	hed[v] = cnt;
    	d[u]++;
    	d[v]++;
	} 
}

void work(int u, int v)
{
    if(g[u][0] && g[u][1])
    {
        if(g[v][1])
        {
            printf("%d %d\n", g[u][1], g[v][1]);
            g[v][1] = g[u][0];
        } else {
            if(g[v][0])
            {
                printf("%d %d\n", g[u][1], g[v][0]);
                g[v][0] = g[u][0];    
            } else {
                g[v][0] = g[u][0];
                g[v][1] = g[u][1];
            }
        }
    }
    if(g[u][0] && !g[u][1])
    {
        if(g[v][1])
        {
            printf("%d %d\n", g[u][0], g[v][1]);
            g[v][1] = 0;   
        } else {
            if(g[v][0])
            {
                g[v][1] = g[u][0];
            } else {
                g[v][0] = g[u][0];
            }
        }
    }
}
int main()
{
    read();
    if(n==1) printf("1\n1 1\n");
	if(n==2) printf("1\n1 2\n");
    
    if(n >= 3)
    {
        l = 0; r = -1;
        for (int i = 1; i <= n; i++) 
        {
    	    if (d[i]==1)
            {
                list[++r] = i;
                g[i][0] = i; g[i][1] = 0;
            }
        }
        printf("%d\n", (r+2)/2);
        int u, e, v;
        while(l <= r)
        {
            u = list[l];
            e = hed[u];
            while(vist[e] && e) e = nexte[e];
            vist[e] = 1;
            if(e%2==0) vist[e-1] = 1;
            if(e%2==1) vist[e+1] = 1;
			v = edge[e];
            
            work(u, v);
            d[u]--; d[v]--;
            if(d[v]==1) list[++r] = v;
            if(l == r) {
                if(g[u][0] && g[u][1]) printf("%d %d\n", g[u][0], g[u][1]);
                if(g[u][0] && !g[u][1]) printf("%d %d\n", u, g[u][0]);
            }
            ++l;
        }
    }
	return 0;
}
