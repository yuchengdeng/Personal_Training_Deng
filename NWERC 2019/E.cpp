#include<cstdio>
#include<algorithm>

int a[5], aim, sum;

int main() {
    for(int i = 1; i <= 4; i++) {
        double x;
        scanf("%lf", &x);
        a[i] = x*1000;
        sum += a[i];
    }
    double x;
    scanf("%lf", &x);
    std::sort(a+1, a+5);
    aim = x*1000;
    int tmp = aim*3;
    if(tmp >= sum-a[1])
        printf("infinite\n");
    else if(tmp < sum-a[4]) printf("impossible\n");
    else {
        double ans = tmp-a[2]-a[3];
        ans /= 1000;
        printf("%.2lf\n", ans);
    }
    return 0;
}