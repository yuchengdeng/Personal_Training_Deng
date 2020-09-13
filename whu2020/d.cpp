#include <iostream>
#include <cstdio>
using namespace std;
int t, n, m, c[2000][2000], xc[2000][2000], yc[2000][2000], f[2000][2000];
char s[2020];

void calc_xc() {
    int lst;
    for(int i = 0; i < n; i++) {
        lst = 0;
        for(int j = 0; j < m; j++) {
            xc[i][j] = (c[i][j]==c[i][lst] ? j-lst : 0);
            if(!xc[i][j]) lst = j;
        }
    }
}
void calc_yc() {
    int lst;
    for(int i = 0; i < m; i++) {
        lst = 0;
        for(int j = 0; j < n; j++) {
            yc[j][i] = (c[j][i]==c[lst][i] ? j-lst : 0);
            if(!yc[j][i]) lst = j;
        }
    }
}

int calc_f() {
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0 || c[i][j]!=c[i-1][j-1]) {
                f[i][j] = 1;
            } else {
                f[i][j] = min(f[i-1][j-1], min(xc[i][j],yc[i][j])) + 1;
            }
            ans = max(ans, f[i][j]);
        }
    return ans;
}
int main() {
    scanf("%d\n", &t);
    for(int k = 0; k < t; k++) {
        scanf("%d %d\n", &n, &m);
        for(int i = 0; i < n; i++) {
        	scanf("%s", s);
            for(int j = 0; j < m; j++) {
                c[i][j] = s[j]- 'A';
                xc[i][j] = yc[i][j] = f[i][j] = 0;
            }
            //scanf("\n");
        }

        calc_xc();
        calc_yc();
        printf("%d\n", calc_f());
    }
}
