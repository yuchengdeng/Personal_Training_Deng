#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 40020

void radix(int *str, int *a, int *b, int n, int m) {
    static int count[maxn];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < n;  i++) ++count[str[a[i]]];
    for(int i = 1; i <= m; i++) count[i] += count[i-1];
    for(int i = n-1; i >= 0; i--) b[--count[str[a[i]]]] = a[i];
}

void suffix_array(int *str, int *sa, int n, int m) {
    static int rank[maxn], a[maxn], b[maxn];
    for(int i = 0; i < n; i++) rank[i] = i;
    radix(str, rank, sa, n, m);

    rank[sa[0]] = 0;
    for(int i = 1; i < n; i++) rank[sa[i]] = rank[sa[i-1]] + (str[sa[i]]!=str[sa[i-1]]);
    for(int i = 0; 1<<i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[j] = rank[j] + 1;
            b[j] = j + (1<<i) >= n ? 0 : rank[j+(1 << i)] + 1;
            sa[j] = j;
        }
        radix(b, sa, rank, n, n);
        radix(a, rank, sa, n, n);
        rank[sa[0]] = 0;
        for(int j = 1; j < n; j++) {
            rank[sa[j]] = rank[sa[j-1]] + (a[sa[j-1]] != a[sa[j]] || b[sa[j-1]] != b[sa[j]]);
        }
        /*for(int j = 0; j < n; j++) {
            printf("%d %d %d", sa[j], a[j], b[j]);
            for(int k = sa[j]; k < n; k++) printf("%c", (char)str[k]+'a'-1);
        	printf("\n");	
		}
		printf("\n");*/
    }
}

void calc_height(int *str, int *sa, int *h, int n) {
    static int rank[maxn];
    int k = 0;
    h[0] = 0;
    for(int i = 0; i < n; i++) rank[sa[i]] = i;
    for(int i = 0; i < n; i++) {
        k = k == 0 ? 0 : k - 1;
        if(rank[i] != 0)
            while (str[i+k] == str[sa[rank[i]-1] + k]) ++k;
        h[rank[i]] = k;
    }
}

int check(int *h, int *sa, int n, int m, int x) {
    int cnt = 0, pos = -1, posp = -1;
	for(int i = n-1; i >= 0; i--) {
		++cnt; posp = max(posp, sa[i]);
    	if(i==0 || h[i] < x) {
    		if(cnt >= m) pos = max(pos, posp);
    		cnt = 0; posp = -1;
		}
	}
	return pos;
}
void calc_ans(int *h, int *sa, int n, int m) {
    if(m <= 1) {
    	printf("%d 0\n", n);
    	return ;
	}
    int l = 0, r = n, mid, ans;
    while(l+1 < r) {
    	printf("%d %d\n", l, r);
        mid = (l + r)/2;
        ans = check(h, sa, n, m, mid);
        if(ans == -1) r = mid;
        if(ans >= 0) l = mid;
    }
    ans = check(h, sa, n, m, l);
    if(!l) printf("none\n");
    else printf("%d %d\n", l, ans);
}

char s[maxn];
int sint[maxn], sa[maxn], h[maxn];
int n, m;
int work() {
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n; i++) sint[i] = s[i] - 'a' + 1;
    suffix_array(sint, sa, n, 26);
    calc_height(sint, sa, h, n);
    /*for(int i = 0; i < n; i++) printf("%d ", sa[i]);
    printf("\n");
    for(int i = 0; i < n; i++) {
    	for(int j = sa[i]; j < n; j++) printf("%d ", sint[j]);
    	printf("\n");
	}
    for(int i = 0; i < n; i++) {
    	for(int j = sa[i]; j < n; j++) printf("%c", s[j]);
    	printf("\n");
	}
    for(int i = 0; i < n; i++) printf("%d ", h[i]);
    printf("\n");*/
    calc_ans(h, sa, n, m);
}
int main() {
    while(scanf("%d", &m), m != 0) work();
    return 0;
}
/*
3
baaaababababbababbab
11
baaaababababbababbab
3
cccccc
0
*/
