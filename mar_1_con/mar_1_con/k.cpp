#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 2500
ll f[N+5];
int c[N+5][N+5], n, k;
ll q_power(ll a, int b)
{
	ll ans=1, res=a;
	while(b){
		if(b&1) ans=ans*res%mod;
		res=res*res%mod;
		b>>=1;
	}
	return ans%mod;
}
void cal_c() {
	c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= n; i++){
		c[i][0] = 1;
		for (int j = 1; j <= n; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1])%mod;
	}
} 
void cal_f() {
	f[1] = 0;
	for(int i = 2; i <= k; i++) {
		f[i] = (ll)i;
		f[i] = (f[i] * q_power((ll)(i-1), n-1)) % mod;
	}
}
int main() {
	scanf("%d%d", &n, &k);
	int q;
	for(int i = 1; i < n; i++)
		scanf("%d", &q);
	cal_c(); cal_f();
	ll ans = 0;
	for(int i = 1; i <= k; i++) {
		ans = (ans + mod + ((k-i)%2 ? (-1): 1)*(((ll)c[k][i] * f[i])%mod))%mod;
	}
	printf("%lld\n", ans);
    return 0;
}
