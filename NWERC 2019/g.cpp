#include<cstdio>

const int maxn = 510;

int n, k;
long double p[maxn], ans[maxn];

long double C(int n, int k) {
    if(k > n)   return 0;
    long double ans = 1;
    for(int i = 1, j = k+1; i <= n-k; i++, j++)
        ans = ans*(long double)j/(long double)i;
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%Lf", &p[i]);
    
    if(k == 1) {
        for(int i = 1; i <= n; i++)
            printf("%.12Lf", 100.0/n);
        return 0;
    }
    for(int i = 0; i < n; i++) {
        long double tmp = 0;
        for(int j = 0, t = i; j <= n-k; j++, t = (t-1+n)%n) {
            tmp += p[t];
            ans[i] += C(n-2-j, k-2)*tmp;
        }
    }
    
    for(int i = 0; i < n; i++)  printf("%.12Lf ", ans[i]/C(n, k));

    printf("\n");
}
