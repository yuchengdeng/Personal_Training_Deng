#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t, a, b, c, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
        x = min(c/2, b);
        b -= x; c -= 2*x; x *= 3;
        y = min(a, b/2) * 3;
        printf("%d\n", x+y);
    }
    return 0;
}