#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<cmath>
#include<queue>
#define outt(x) cout<<#x<<"="<<x<<"      "
#define hh  cout<<endl
#define debug cout<<"???" 
using namespace std;
typedef long long ll;
const int maxn = 2e4+100;
const int Inf=1e9+1;
const long long mod = 998244353;
inline int read()
{
    long long fl=1ll,rt=0ll; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1ll; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10ll+ch-'0'; ch=getchar();}
    return fl*rt;
}
int n,m,cnt,q,nowans,totnum;
int hed[maxn],dis[maxn],vis[maxn],lastt[maxn];
long long ui,vi,anss;
long long ans[maxn];
struct EDG
{
    int nxt,val,too,bol,fro;
}edge[maxn*3];
 
struct node{
    int index,dist;
    void printt(){outt(index);outt(dist);hh;}
    bool operator < (const node &x)const
    {
        return dist>x.dist;
    }
};
 
void add_edge()
{
    int a,b,c;
    a=read();b=read();c=read();
    edge[++cnt].val=c;edge[cnt].too=b;edge[cnt].bol=0;
    edge[cnt].nxt=hed[a];hed[a]=cnt;edge[cnt].fro=a;
    return;
} 
 
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
 
void work()
{
    nowans=0;
    priority_queue<node>qq;
    while(totnum<m)
    {
    //  outt(1);
        for(int i=1;i<=n;++i) dis[i]=Inf,vis[i]=0,lastt[i]=0;
        dis[1]=0;
        qq.push(node{1,0});
         while(!qq.empty())
        {
            node x=qq.top();qq.pop();
         //   x.printt();
          //  for(int i=1;i<=2;++i) outt(dis[i]);
          //  hh;
            int u=x.index;
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=hed[u];i;i=edge[i].nxt)
                {
                    if(edge[i].bol==1) continue;
                    if(dis[edge[i].too]>dis[u]+edge[i].val)
                    {
                         lastt[edge[i].too]=i;
                         dis[edge[i].too]=dis[u]+edge[i].val;
                         qq.push(node{edge[i].too,dis[edge[i].too]});
                    }
                }
        }
      //  outt(dis[n]);hh;
        if(dis[n]==Inf) break;
        totnum++;
        int nowwa;
        nowwa=n;ans[++nowans]=dis[n];
    //  outt(lastt[nowwa]);
        while(nowwa!=1)
        {
            edge[lastt[nowwa]].bol=1;
            nowwa=edge[lastt[nowwa]].fro;
        }
    //  for(int i=1;i<=cnt;++i) outt(edge[i].bol);
    }
    return;
}
 
int main()
{
    while(~scanf("%d",&n))
    {
        m=read();cnt=0;nowans=0;totnum=0;
        for(int i=1;i<=n;++i) hed[i]=0; 
        for(int i=1;i<=m;++i) add_edge();
    //  outt(11);
        ans[0]=0ll;work();
    //  outt(nowans);hh;
        for(int i=1;i<=nowans;++i) ans[i]=ans[i]+ans[i-1];
        q=read();
        for(int i=1;i<=q;++i) 
        {
            ui=read();vi=read();
            if(ui==0) {printf("NaN\n");continue;}
            long long qwq,poi,qwer;
            qwq=vi/ui;anss=ui*ans[qwq];
            if(vi%ui)
            {
                anss+=(vi%ui)*(ans[qwq+1]-ans[qwq]);
                qwq++;
            }
        //  outt(qwq);
            if(qwq>nowans){printf("NaN\n");continue;}
            qwq=gcd(anss,vi);anss/=qwq;vi/=qwq;         
            printf("%lld/%lld\n",anss,vi);
        }
    }
    return 0;
}
/*
3 3
1 2 1
1 2 2
2 3 2
3
1 2
2 3
1 4
*/