#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 300000
#define ll long long
int n, w, k, c;
ll tag[maxn+10], ans[maxn+10];
int q[maxn+10], point[maxn+10], p;
int main() {
    scanf("%d%d", &n, &w);
    for(int i = 1; i <= n; i++) ans[i] = w;
    q[0] = n;
    for(int t = 1; t <= w; t++) {
        scanf("%d", &k);
        for(int j = 1; j <= k; j++) {
            scanf("%d", &c);
            p = point[c];
            ans[c] += (ll)(-q[p+1]*(ll)(w-t+1)) + (ll)tag[p] - (ll)tag[p+1];
            tag[p] += (ll)(w-t+1);
            q[p]--;
            q[p+1]++;
            point[c]++;
        }
    }
    for(int i = 1; i<= n; i++) printf("%.10lf\n", (ans[i]+tag[point[i]])*1.0/w );
    return 0;
}