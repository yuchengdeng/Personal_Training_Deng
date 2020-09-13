#include <iostream>
#include <cstdio>
using namespace std;
struct A{
    int x1, y1, x2, y2;
} ans[100050];

int t, a, b, n, x, y, xx, yy, typ;
int x1, y1, x2, y2, cnt;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &n);
        xx = 1; yy = 1;
        if(a<0) {xx = -1; a = -a;} else xx = 1;
        if(b<0) {yy = -1; b = -b;} else yy = 1;
        x = y = 0; typ = 0; cnt = 0;
        while(!((x1>=a && y1>=b)||(x2>=a && y2>=b))) {
            if(a-x<n && b-y <n) {
                if(!typ) {
                    x1 = a; y1 = y+n-1;
                    x2 = a-n+1; y2 = y;
                } else {
                    x1 = x; y1 = b-n+1;
                    x2 = x+n-1; y2 = b;
                }
            }
            if(a-x>=n && b-y<n) {
                typ = 1;
                x1 = x+n-1; y1 = y-n+1;
                x2=x; y2=y;
                x += n;
            }
            if(a-x<n && b-y>=n) {
                typ = 0;
                x1=x; y1=y;
                x2=x-n+1; y2=y+n-1;
                y+=n;
            }
            if(a-x>=n && b-y>=n) {
            	x1=x+n-1; y1=x+n-1;
                x2=x; y2=y;
                if(a-x >= b-y) {
                    typ=1;
                    x=x+n; y=y+n-1;
                } else {
                    typ=0;
                    x=x+n-1; y=y+n;
                }
            }
            ans[++cnt].x1 = x1*xx; ans[cnt].y1 = y1*yy; ans[cnt].x2 = x2*xx; ans[cnt].y2 = y2*yy;
        }
        printf("%d\n", cnt);
        for(int i = 1; i<=cnt; i++)
            printf("%d %d %d %d\n", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2);
    }
    return 0;
}
