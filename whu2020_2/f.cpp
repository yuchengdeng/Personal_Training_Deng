#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;
#define ll long long
char s[50], t[50];
ll p[50], sa[128], ta[128];
int n;
void calc_p() {
    p[1] = 1; p[2] = 0;
    for(int i = 3; i <= 45; i++)
        p[i] = p[i-1] + p[i-2];
}
int main() {
    calc_p();
    scanf("%s", s);scanf("%s", t);
    scanf("%d", &n);
    int lens = strlen(s), lent = strlen(t);
    for(int i = 0; i < lens; i++){
        sa[s[i]]++;
    } 
    for(int i = 0; i < lent; i++) {
        ta[t[i]]++;
    }
    for(int i = 'A'; i <= 'Z'; i++)
        if(sa[i]*p[n] + ta[i]*p[n+1]!= 0)
            printf("%c: %lld\n", i, sa[i]*p[n] + ta[i]*p[n+1]);
    for(int i = 'a'; i <= 'z'; i++)
        if(sa[i]*p[n] + ta[i]*p[n+1]!= 0)
            printf("%c: %lld\n", i, sa[i]*p[n] + ta[i]*p[n+1]);
    return 0;
}