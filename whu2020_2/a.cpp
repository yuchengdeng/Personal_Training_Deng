#include <iostream>
#include <cstdio>
using namespace std;
int e, b, x, n, m, t, a, ans;
int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d%d%d", &n, &m, &x);
        e = b = 0;
        for(int i = 1; i < n; i++) {
            scanf("%d", &a);
            if(a == x) e++;
            if(a > x) b++;
        }
        if(n-e >= m) printf("%d\n", b+1);
        if(n-e < m) printf("%d\n", b+1+(m-n+e)); 
    }
    return 0;
}