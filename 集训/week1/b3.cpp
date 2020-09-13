#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
ll n, m;
ll ksm(ll a,ll b, ll mod) {
    ll c = 1;
    while(b)
    {
        if (b & 1) c= c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}
int main() {
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", ksm(ksm(2, m, MOD)+MOD-1, n, MOD));
    return 0;
}