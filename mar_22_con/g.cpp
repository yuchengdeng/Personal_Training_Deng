#include <iostream>
#include <cstdio>
#define maxn 10000
#define maxx 1000
int n, k;
int x[maxx+5], mxx[maxn+5], sxx[maxn+5], ck = -1, upd, sum, a, b, c;
int main() {
	freopen("generators.in", "r", stdin);
    freopen("generators.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &x[0], &a, &b, &c);
        for(int j = 1; j <= c; j++) {
            x[j] = ((a*x[j-1]) + b) % c;
            mxx[i] = (x[mxx[i]] < x[j] ? j : mxx[i]);
        }
        sxx[i] = -1; 
        sum += x[mxx[i]];
        for(int j = 0; j <= c; j++)
            sxx[i] = ( (((sxx[i] == -1)||(x[sxx[i]] < x[j]))&&((x[mxx[i]] - x[j])%k !=0)) ? j : sxx[i]);
        if((sxx[i]!=-1)&&((ck == -1)||(x[mxx[i]]-x[sxx[i]] < upd))) {
            ck = i;
            upd = x[mxx[i]]-x[sxx[i]];
    	}
    }
    if(ck != -1 && sum % k == 0) {
        sum -= upd; 
        mxx[ck] = sxx[ck];
    }
    if(ck == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", sum);
        for(int i = 1; i <= n-1; i++) 
            printf("%d ", mxx[i]);
        printf("%d\n", mxx[n]);
    }
    return 0;
}
