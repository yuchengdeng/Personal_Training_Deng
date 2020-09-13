#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 30
#define maxs 100
#define maxc 1000000
int n, q, s, t;
int qs[maxs+5], cq[maxn+5], d, nowd, qr[maxn+5], sum;
bool pd;
int nowq[maxn+5];
int main() {
    scanf("%d%d%d", &n, &q, &s);
    for(int i = 1; i <= s; i++) scanf("%d", &qs[i]);
    for(int i = 1; i <= q; i++) scanf("%d", &cq[i]);
    nowd = 0; pd = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &d);
        for(int j = 1; j <= q; j++) qr[j] = 0;
        for(int j = 1; j <= s; j++) {
			scanf("%d", &t);
			if(t > cq[j]) {
				pd = 1; 
				break;
			} 
			qr[qs[j]] += t;
		}
        for(int j = 1; j <= q; j++) {
        	if(qr[j] > cq[j]) {
        		pd = 1;
        		break;
			}
			nowq[j] += qr[j];
            if(nowq[j] > cq[j]) {
                if(nowd >= (nowq[j] - cq[j])) {
                    nowd -= (nowq[j] - cq[j]);
                    nowq[j] = cq[j];
                } else {
                    pd = 1;
                    break;
                }
            }
        }
        if(pd) break;
        nowd += d;
        sum = 0;
        for(int j = 1; j <= q; j++)
            sum += nowq[j];
        if(sum <= nowd)
        {
            nowd = 0;
            for(int j = 1; j <= q; j++)
                nowq[j] = 0;
        }
    }
    for(int i = 1; i <= q; i++) nowd -= nowq[i];
    if(nowd < 0) pd = 1;
    if(pd) {
        printf("impossible\n");
    }
    else
    {
        printf("possible\n");
    }
    return 0;
}
