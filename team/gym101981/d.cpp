#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 105
int n, ax[maxn], ay[maxn], az[maxn], cnt; 
double x[maxn*maxn], y[maxn*maxn], z[maxn*maxn];
double ans, dis, disp;
double sqr(double u) {
    return u*u;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d%d", &ax[i], &ay[i], &az[i]);
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) {
            x[++cnt] = (ax[i]+ax[j]) / 2.0;
            y[cnt]   = (ay[i]+ay[j]) / 2.0;
            z[cnt]   = (az[i]+az[j]) / 2.0;
        }
    ans = 4e10;
    for(int i = 1; i <= cnt; i++) {
        disp = 0;
        for(int j = 1; j <= n; j++) {
            dis = sqr(ax[j]-x[i]) + sqr(ay[j]-y[i]) + sqr(az[j]-z[i]);
            if(dis > disp) disp = dis; 
        }
        if(disp < ans) ans = disp;
    }
    printf("%.15lf", sqrt(ans));
    return 0;
}