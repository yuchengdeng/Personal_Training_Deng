#include<cstdio>

const int maxn = 510;

int n, k;
double p[maxn], ans[maxn];
double C[510][510];

void make_C() {
    for(int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
}


int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lf", &p[i]);
    make_C();

    if(k == 1) {
        for(int i = 1; i <= n; i++)
            printf("%.10lf ", 100.0/n);
        return 0;
    }

    for(int i = 0; i < n; i++) {
        double tmp = 0;
        for(int j = 0, t = i; j <= n-k; j++, t = (t-1+n)%n) {
            tmp += p[t];
            ans[i] += C[n-2-j][k-2]*tmp;
        }
    }

    for(int i = 0; i < n; i++)  {
        printf("%.10lf ", ans[i]/C[n][k]);
    }

    printf("\n");

    return 0;
}