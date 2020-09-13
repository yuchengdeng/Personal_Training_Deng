#include <iostream>  
#include <algorithm>   
#include <string.h> 
#include <queue>
using namespace std;
#define ll long long
const int MaxN = 100010, MaxsigS = 1000010;
const ll  MaxDis = 1e18+10;

struct edge
{
    int to, next;
    ll dis;
};

edge e[MaxsigS * 2];
int head[MaxN*2], cnt;
ll dis[2][MaxN*2];
bool vis[2][MaxN*2];
int n, m;

inline void add_edge( int u, int v, ll d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

/*struct node
{
    ll dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

std::priority_queue<node> q;


inline void dijkstra(int st, int s)
{
	while(!q.empty()) q.pop();
    dis[st][s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos; ll d = tmp.dis;
        if( vis[st][x] )
            continue;
        vis[st][x] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[st][y] > dis[st][x] + e[i].dis )
            {
                dis[st][y] = dis[st][x] + e[i].dis;
                if( !vis[st][y] )
                {
                    q.push( ( node ){dis[st][y], y} );
                }
            }
        }
    }
}
*/

void SPFA(int xx, int st)  
{  
    for (int i=0;i<=m+n;i++)
    dis[xx][i]=MaxDis;
    queue<int>q;
    int w,v;
    memset(vis[xx],false,sizeof(vis[xx]));
    while (!q.empty())q.pop();
    q.push(st);
    dis[xx][st]=0;
    vis[xx][st]=true;
    while (!q.empty())
    {
    	v=q.front();
    	q.pop();
    	vis[xx][v]=false;
    	for (int i=head[v];i!=-1;i=e[i].next)
    	{
    		w=e[i].dis;
    		if (w+dis[xx][v]<dis[xx][e[i].to])
    		{
    			dis[xx][e[i].to]=w+dis[xx][v];
    			if (!vis[xx][e[i].to])
    			{
    				vis[xx][e[i].to]=true;
    				q.push(e[i].to);
				}
			}
		}   
    }
}
int prework() {
    scanf("%d%d", &n, &m);
    /*for(int i = 1; i <= n+m; ++i) { 
        dis[0][i] = dis[1][i] = MaxDis;
        vis[0][i] = vis[1][i] = 0;
        head[i] = 0;
    }*/
    memset(head,-1,sizeof(head));
    cnt = 0;
    int v, s; ll d;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%lld%d", &d, &s);
        for(int j = 1; j <= s; j++) {
            scanf("%d", &v);
            add_edge(n+i, v, d);
            add_edge(v, n+i, d);
        }
    }
    return 0;
}

int main()
{
    int T;
    int nexta[MaxN], heada;
    bool flag;
    ll ans, ansk;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        prework();
        //dijkstra(0, 1); dijkstra(1, n);
        SPFA(0, 1); SPFA(1, n);
        /*ans = MaxsigS; heada = -1;
        for(int j = n; j >= 1; j--) {
            ansk = (dis[0][j]>dis[1][j]?dis[0][j]:dis[1][j]);
            if(ansk < ans) {
                ans = ansk;
                nexta[j] = -1; heada = j;
            } else if(ansk == ans) {
                nexta[j] = heada; heada = j;
            }
        }*/
        ans = MaxsigS;
        for(int j = 1; j <= n; j++) {
        	dis[0][j] = dis[1][j] = max(dis[0][j], dis[1][j]);
        	ans = min(ans, dis[0][j]);
		}
        	
        printf("Case #%d: ", i);
        if(ans == MaxsigS) printf("Evil John\n");
        if(ans < MaxsigS) {
            printf("%lld\n", ans/2);
            /*while(nexta[heada] != -1) {
                printf("%d ", heada);
                heada = nexta[heada];
            }
            printf("%d\n", heada);*/
            flag = 0;
            for(int j = 1; j <= n; j++)
            	if(dis[0][j] == ans) {
            		if(!flag) {
						printf("%d", j);
						flag = 1;
					}
            		else printf(" %d", j);
				}
			printf("\n");
        }
    }
    return 0;
}
