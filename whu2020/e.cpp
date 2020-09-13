#include <iostream>
#include <cstdio>
using namespace std;
int t;
long long n;
int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%lld", &n);
        if(n >= 1) printf("%lld\n", n-1);
        if(n == 0) printf("%lld\n", n);
    }
    return 0;
}