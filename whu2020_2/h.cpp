#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 20000
char s1[N+50], s2[N+50];
int next_x[N+50], hp1, hp2, n, t;
bool ora[N+50], muda[N+50], zawa1[N+50], zawa2[N+50];
void cal_next_x(char *str, int *next_x, int len){
	int k = -1;
	next_x[0] = -1;
	for(int q = 1; q <= len-1; q++){
		while(k>-1 && str[k+1]!=str[q])
			k = next_x[k];
		if(str[k+1]==str[q])
			k++;
		next_x[q] = k;
	}
}

void kmp(char *str, char *ptr, int *next_x, bool *ans){
	int slen = strlen(str), plen = strlen(ptr), k;
	cal_next_x(ptr, next_x, plen);
	k = -1;
    for(int i = 0; i < slen; i++) ans[i] = 0;
	for(int q = 0; q < slen; q++){
		while(k > -1 && ptr[k+1] != str[q])
			k = next_x[k];
		if(ptr[k+1] == str[q])
			k++;
		if(k == plen-1){
			ans[q] = 1;
			k = next_x[k];
		}
	}
}


int main(){
	scanf("%d", &t);
    for(int k = 0; k < t; k++) {
        scanf("%d%d%s%s", &n, &hp1, s1, s2);
        hp2 = hp1;
        char sora[5] = "ora\0";
        char smuda[6] = "muda\0";
        char szawa[11] = "zawaluduo\0";
        kmp(s1, sora, next_x, ora);
        kmp(s2, smuda, next_x, muda);
        kmp(s1, szawa, next_x, zawa1);
        kmp(s2, szawa, next_x, zawa2);
        bool ss = 0;
        for(int i = 0; i < n; i++) {
            if(zawa2[i]) {printf("Hinnjaku\n"); ss = 1; break;}
            if(zawa1[i]) {printf("Wryyyyy\n"); ss = 1; break;}
            hp1 -= muda[i]; hp2 -= ora[i];
            if(hp1 && !hp2) {printf("Wryyyyy\n"); ss = 1; break;}
            if(!hp1 && hp2) {printf("Hinnjaku\n"); ss = 1; break;}
            if(!hp1 && !hp2) {printf("Kono Dio da\n"); ss = 1; break;}
        }
        if(!ss) {
            if(hp1 > hp2) printf("Wryyyyy\n");
            if(hp2 > hp1) printf("Hinnjaku\n");
            if(hp1 == hp2) printf("Kono Dio da\n");
        }
    }
	return 0;
} 
