#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 400200

char s[maxn];
int y[maxn],x[maxn],c[maxn],sa[maxn],rank[maxn],h[maxn],wt[30];
int n,m,cm;
void putout(int x)
{
    if(!x) {putchar(48);return;}
    int l=0;
    while(x) wt[++l]=x%10,x/=10;
    while(l) putchar(wt[l--]+48);
}
void get_SA()
{
    for (int i=1;i<=n;++i) ++c[x[i]=s[i]];
    for (int i=2;i<=m;++i) c[i]+=c[i-1]; 
    for (int i=n;i>=1;--i) sa[c[x[i]]--]=i; 
    for (int k=1;k<=n;k<<=1)
    {
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        for (int i=1;i<=m;++i) c[i]=0;
        for (int i=1;i<=n;++i) ++c[x[i]];
        for (int i=2;i<=m;++i) c[i]+=c[i-1];
        for (int i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1;num=1;
        for (int i=2;i<=n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
        if (num==n) break;
        m=num;
    }
    for (int i=1;i<=n;++i) putout(sa[i]),putchar(' ');
}
void get_h()
{
    int k=0;
    for (int i=1;i<=n;++i) rank[sa[i]]=i;
    for (int i=1;i<=n;++i)  
    {
        if (rank[i]==1) continue;
        if (k) --k;
        int j=sa[rank[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        h[rank[i]]=k;
    }
    putchar(10);for (int i=1;i<=n;++i) putout(h[i]),putchar(' ');
}

int check(int *h, int *sa, int n, int m, int x) {
    int cnt = 0, pos = -1, posp = -1;
	for(int i = n; i >= 1; i--) {
		++cnt; posp = max(posp, sa[i]);
    	if(i==1 || h[i] < x) {
    		if(cnt >= m) pos = max(pos, posp);
    		cnt = 0; posp = -1;
		}
	}
	return pos;
}
void calc_ans(int *h, int *sa, int n, int m) {
    if(m <= 1) {
    	printf("%d 0\n", n);
    	return ;
	}
    int l = 0, r = n, mid, ans;
    while(l+1 < r) {
    	printf("%d %d\n", l, r);
        mid = (l + r)/2;
        ans = check(h, sa, n, m, mid);
        if(ans == -1) r = mid;
        if(ans >= 0) l = mid;
    }
    ans = check(h, sa, n, m, l);
    if(!l) printf("none\n");
    else printf("%d %d\n", l, ans-1);
}

int work() {
    scanf("%s", s+1);
    n=strlen(s+1); m=122;
    get_SA();
    get_h();
    for(int i = 1; i <= n; i++) printf("%d ", sa[i]);
    printf("\n");
    for(int i = 1; i <= n; i++) {
    	for(int j = sa[i]; j <= n; j++) printf("%c", s[j]);
    	printf("\n");
	}
    for(int i = 1; i <= n; i++) printf("%d ", h[i]);
    printf("\n");
    calc_ans(h, sa, n, cm);
}
int main() {
    while(scanf("%d", &cm), cm != 0) work();
    return 0;
}
