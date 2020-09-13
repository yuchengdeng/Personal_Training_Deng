#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 200010
int t, n;
int e, a[maxn], b, ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        for(int i = 1; i <= n; i++) a[i] = 0;
        b = ans= 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &e);
            a[e]++;
        }
        for(int i = 1; i <= n; i++) {
            ans += (a[i] + b)/i;
            b = (a[i] + b) % i;
        }
        printf("%d\n", ans);
    }
    return 0;
}