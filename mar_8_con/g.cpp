#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
ll a, b;
int n;
char sa[70], sb[70];
ll gtob(char *s) {
    ll ans = s[0] - '0';
    ll la = ans;
    for(int i = 1; i < n; i++) {
        ans *= 2;
        la = (la^(s[i]-'0'));
        ans += la;
    }
    return ans;
}
int main() {
    scanf("%d %s %s", &n, sa, sb);
    a = gtob(sa); b = gtob(sb);
    printf("%lld\n", b - a - 1);
    return 0;
}
