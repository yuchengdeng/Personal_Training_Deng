#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1000010
int n, k;
bool f[maxn], sum;
int main() {
    scanf("%d%d", &n, &k);
    f[1] = sum = 1;
    for(int i = 2; i <= n; i++) {
        if(sum == min(k, i-1))  f[i] = 0;
            else                f[i] = 1;
        if(i-k > 0) sum -= f[i-k];
        sum += f[i];
    }
    if(f[n]) printf("Adrien\n");
        else printf("Austin\n");
    return 0;
}