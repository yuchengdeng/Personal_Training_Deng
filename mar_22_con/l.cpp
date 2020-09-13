#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define maxw 100000
int w;
ll n;
ll h[maxw+10];
ll sumh[maxw+10];
int le[maxw+10], re[maxw+10], list[maxw+10];
void calc_e(ll tgt) {
    int l = 1, r = 1; list[1] = 0;
    for(int i = 1; i <= w; i++) {
    	while(l <= r && h[list[r]] + (ll)i - (ll)list[r] < h[i]) r--;
        list[++r] = i;
        while(l < r && h[list[l+1]] + (ll)i - (ll)list[l+1] >= tgt) l++;
        if(h[list[l]] + (ll)i - (ll)list[l] >= tgt) le[i] = list[l];
        else le[i] = -1;
        if(le[i]==i) le[i]--;
    }
    l = 1; r = 1; list[1] = w+1;
    for(int i = w; i >= 1; i--) {
    	while(l <= r && h[list[r]] + (ll)list[r] - (ll)i < h[i]) r--;
        list[++r] = i;
        while(l < r && h[list[l+1]] + (ll)list[l+1] - (ll)i>= tgt) l++;
        if(h[list[l]] + (ll)list[l] - (ll)i>= tgt) re[i] = list[l];
        else re[i] = -1; 
        if(re[i]==i) re[i]++;
    }
    //for(int i = 1; i <= w; i++) printf("%d %d\n", le[i], re[i]);
}
bool checkans(ll tgt) {
    ll ansk;
    calc_e(tgt);
    for(int i = 1; i <= w; i++) {
    	if(le[i] == -1 || re[i] == -1) continue;
        ansk = (tgt - (ll)(i-le[i]-1) +tgt)*(ll)(i-le[i])/2 - tgt - sumh[re[i]-1] + (tgt - (ll)(re[i]-i-1) +tgt)*(ll)(re[i]-i)/2  + sumh[le[i]];
        if(ansk <= n) return 1;
    }
    return 0;
}

ll readin() {
	ll maxx = 0;
    scanf("%d%lld", &w, &n);
    sumh[0] = 0;
    for(int i = 1; i <= w; i++) {
        scanf("%lld", &h[i]);
        sumh[i] = sumh[i-1] + h[i];
		maxx = max(h[i], maxx);
	}
    h[0] = h[w+1] =  0;
    return maxx;
}
int main() {
	freopen("landscape.in", "r", stdin);
    freopen("landscape.out", "w", stdout);
	ll lb = readin();
    ll l=lb, r=2000000000, Mid, ans;
    while(l<=r){
        Mid=(l+r)/2;
        if(checkans(Mid)) l=Mid+1,ans=Mid;
        else r=Mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}
