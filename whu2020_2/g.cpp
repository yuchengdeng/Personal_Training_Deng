#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 101
int a[maxn], b[maxn], c[maxn], n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    int d, s0, s1, s2;
    s0 = -1e9;
    for(int i = 0; i < n; i++) {
        d = a[i]; s1 = 1e9;
        for(int j = 0; j < n; j++) {
            d += b[j]; s2 = d + c[0]; 
            for(int k = 1; k < n; k++)
                s2 = (abs(d+c[k]) < abs(s2)? d+c[k] : s2);
            s1 = (s2 < s1 ? s2 : s1);
            d -= b[j];
        }
        s0 = (s1 > s0 ? s1 : s0);
    }
    printf("%d\n", s0);
    return 0;
}
