#include<cstdio>
#include<algorithm>

int a[5], aim, sum;

int main() {
    for(int i = 1; i <= 4; i++) {
        int x, y;
        scanf("%d.%d", &x, &y);
        a[i] = x*100 + y;
        sum += a[i];
    }
    int x, y;
    scanf("%d.%d", &x, &y);
    std::sort(a+1, a+5);
    aim = x*100+y;
    int tmp = aim*3;
    if(tmp >= sum-a[1])
        printf("infinite\n");
    else if(tmp < sum-a[4]) printf("impossible\n");
    else {
        int ans = tmp-a[2]-a[3];
        if(ans%100 >=10)
            printf("%d.%d", ans/100, ans%100);
        else 
            printf("%d.0%d", ans/100, ans %100); 
    }
    return 0;
}
