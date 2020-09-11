#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[3*100005], b[3*100005];
int la, lb, ans;
int main() {
    while(~scanf("%s", a)) {
        scanf("%s", b);
        la = strlen(a);
        lb = strlen(b);
        if(la <= lb) {
            for(int i = la; i < 2*lb; i++)
                a[i] = a[i%la];
            for(int i = lb; i < 2*lb; i++)
                b[i] = b[i%lb];
        }
        if(lb < la) {
            for(int i = lb; i < 2*la; i++)
                b[i] = b[i%lb];
            for(int i = la; i < 2*la; i++)
                a[i] = a[i%la];
        }
        ans = -1;
        for(int i = 0; i < 2* max(la, lb); i++) {
            if(a[i]==b[i]) continue;
            ans = a[i]> b[i];
            break;
        }
        if(ans == -1) {
            printf("=\n");
            continue;
        }
        if(ans == 0) {
            printf("<\n");
            continue;
        }
        if(ans == 1) {
            printf(">\n");
            continue;
        }
    }
    return 0;
}