#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1000000
int n, s[maxn+10], ls[maxn+10];
bool sta;
int cnt, l, r;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
    s[n+1] = 2e9;
    ls[1] = 1;
    for(int i = 2; i <= n; i++)
        if(s[i] == s[ls[i-1]]) ls[i] = ls[i-1];
            else ls[i] = i;
    for(int i = 1; i <= n; i++) {
        if(sta == 0 && s[i] < s[i-1]) {
            sta = 1; l = ls[i-1]; cnt++;
        } else {
            if(sta == 1 && s[i] > s[i-1]) {
                sta = 0; r = i-1;
            }
        }
    }
    if(sta == 1) r = n;
    if(cnt == 0) printf("1 1\n");
    if(cnt > 1)  printf("impossible\n");
    if(cnt == 1) {
        if(s[l-1] <= s[r] && s[l] <= s[r+1])
            printf("%d %d\n", l, r);
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
