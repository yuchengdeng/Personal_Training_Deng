#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
bool checkx(int a, int a1, int b, int c, int d, int d1) {
	//cout << a <<" " << a1 <<" "<< d <<" "<< d1<<endl;
    if((ll)a1*(ll)(a1-1) != (ll)a * 2) return 0;
    if((ll)d1*(ll)(d1-1) != (ll)d * 2) return 0;
    if((ll)a1*(ll)d1 != (ll)b + (ll)c) return 0;
    return 1;
}
bool checkx2(int a, int a1, int b, int c, int d, int d1){
	if(!a && !b && !c && !d) { printf("0"); return 0;}
	if(!a && !b && !c && d && (ll)d1*(ll)(d1-1) == (ll)d * 2)  { for(int i = 1; i <= d1; i++) printf("1"); return 0;}
	if(a && !b && !c && !d && (ll)a1*(ll)(a1-1) == (ll)a * 2)  { for(int i = 1; i <= a1; i++) printf("0"); return 0;}
	return 1; 
}
int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
	int a1 = ((int) sqrt(a*2)) + 1;
    int d1 = ((int) sqrt(d*2)) + 1;
    if(checkx(a, a1, b, c, d, d1)) {
        while(a1 != 0 && d1 != 0) {
            if(b >= d1) {
                a1 -= 1;
                b -= d1;
                printf("0");
            } else {
                d1 -= 1;
                printf("1");
            }
        }
        for(int i = 1; i <= a1; i++) printf("0");
        for(int i = 1; i <= d1; i++) printf("1");
    } else {
        if(checkx2(a, a1, b, c, d, d1)) printf("impossible");
    }
    printf("\n");
    return 0;
}
