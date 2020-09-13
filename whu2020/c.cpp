#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100000
int n, t, a[maxn+5], ans[maxn+5], b[maxn+5], rbh, Log[maxn+5];
int f[maxn+5][30];

void RMQ()
{
	int i,j;
	for(i=1;i<=n;++i)
	  f[i][0]=i;
	for(j=1;(1<<j)<=n;++j)
	  for(i=1;i+(1<<(j-1))<=n;++i) {
          int x = f[i][j-1], y = f[i+(1<<(j-1))][j-1];
          if(a[x] < a[y] ||(a[x]==a[y] && x > y)) {
              f[i][j] = f[i][j-1];
          } else {
              f[i][j] = f[i+(1<<(j-1))][j-1];
          }
      }
	    
}

void GetLog()
{
	int i;
	Log[1]=0;
	for(i=2;i<=n+1;++i)
	  Log[i]=Log[i/2]+1;
}

int find (int l, int r) {
    int ans;
    int k=Log[r-l+1];
    int x = f[l][k], y = f[r-(1<<k)+1][k];
    if(a[x] < a[y] ||(a[x]==a[y] && x > y)) {
        ans = x;
    } else {
        ans = y;
    }
	return ans;
}
void solve(int l, int r, int mini, int maxi, int key) {
    if(l > r) return;
    int now = find(l, r);
    if(a[now] != key)
        now = b[l];
    ans[now] = mini;
    solve(l, now-1, mini+1, mini+now-l, key);
    solve(now+1, r, mini+now-l+1, maxi, key+1);
}

int main() {
    scanf("%d", &t);
    n = maxn;
    GetLog();
    for(int k = 0; k < t; k++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(a[i] < 0) a[i] = n+1;
        }
        for(int i = n; i >= 1; i--) {
            if(a[i]==n+1) b[i] = rbh = i;
            if(a[i]!=n+1) b[i] = rbh;
        }
        RMQ(); 
        solve(1, n, 1, n, 1);
        for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
