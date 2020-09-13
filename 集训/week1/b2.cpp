#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
ll pnexta(ll a) {
    int mx = 0, mn = 9, b;
    while(a) {
        b = a%10;
        mx = max(mx, b); mn = min(mn, b);
        a /= 10;
    }
    return a + (ll)(mx*mn);
}
int main() {
    int t;
    ll a, p, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &a, &k);
        while(--k) {
            p = a; a = a + pnexta(a);
            if(p == a) break;
        }
        printf("%lld\n", a);
    }
    return 0;
}