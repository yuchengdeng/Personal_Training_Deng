#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 500000
#define ll long long
ll a[41], ans;
int n, p;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        a[p+20]++;
    }
    for(int i = 0; i < 20; i++)
        ans += a[i]*a[40-i];
    ans += a[20]*(a[20]-1)/2;
    printf("%lld\n", ans);
    return 0;
}
