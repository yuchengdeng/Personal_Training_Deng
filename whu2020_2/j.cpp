#include<iostream>
#include <cstdio>
using namespace std;
#define P 998244353
#define maxn 100000
#define ll long long
ll fac [2*maxn+5];
void cal(){  
    fac[0]=1;  
    for(int i=1;i<=maxn*2+1;i++) fac[i]=fac[i-1]*i%P;  
}  
  
inline ll qpow(ll a,ll b){  
    ll ans=1;  
    for(;b;b>>=1,a=a*a%P) if(b&1) ans=ans*a%P;
    return ans;  
}  
  
inline ll C(ll n,ll m){  
    if(n<m) return 0;  
    return fac[n]*qpow(fac[n-m]*fac[m]%P,P-2)%P;  
}

int main() {
    cal();
    int n;
    scanf("%d", &n);
    ll ans = 0, ansp;
    for(int i = 0; i <= n; i++) {
        ansp = C(2*i, i)*C(n+i, n-i)%P;
        ansp = ansp*qpow((i+1)%P, P-2)%P;
        ans = (ans+ansp)%P;
    } 
    printf("%lld\n", ans);
    return 0;
}