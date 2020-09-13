#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define M 1e9+7

ll ksm(ll a, ll b, ll m){
	if(b == 0)
		return 1;
	else if(b % 2 == 1)
		return a * ksm(a, b - 1, m) % m;
	else{
		ll num = ksm(a, b/2, m) % m;
		return num * num % m;
	}
	
}

inline ll ksc(ll x,ll y,ll p){
	ll z=(ld)x/p*y;
	ll res=(ull)x*y-(ull)z*p;
	return (res+p)%p;
}
int t;
ll m, n, a, b;
int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%lld%lld", &n, &m);
        n = n- m;
        a = ksm(2, n, M);
        b = ksm(2, m-1, M);
        b = ksc(m, b, M);
        a = ksc(a, b, M);
        printf("%lld\n", a);
    }
    return 0;
}
