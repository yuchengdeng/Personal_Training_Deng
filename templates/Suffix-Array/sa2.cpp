#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1000010

struct suffix_array {
    int *sa, *rank, *height, *str;
    int self[maxn], s1[maxn], s2[maxn], buk[maxn];
    int n, m;

    void basesort(int *a, int *b, int *c, int n, int m) { //基数排序
        memset(buk, 0, sizeof(buk));
        for(int i = 0; i < n; i++) buk[b[a[i]]]++;
        for(int i = 0; i <= m; i++) buk[i] += buk[i-1];
        for(int i = n-1; i >= 0; i--) c[--buk[a[b[i]]]] = b[i];
    }

    bool cmp(int *str, int *s1, int *s2, int g, int x) {
        if(g) return s1[sa[x]]!=s1[sa[x-1]] || s2[sa[x]] != s2[sa[x-1]];
        else return str[sa[x]]!=str[sa[x-1]]; 
    }

    void calc_rank(int *str, int *s1, int *s2, int g) { //更新rank[]
        rank[sa[0]] = 0;
        for(int i = 1; i < n; i++) {
            rank[sa[i]] = rank[sa[i-1]] + cmp(str, s1, s2, g, i);
        }
    }

    void get_sa() { //求SA
        for(int i = 0; i < n; i++) self[i] = i;
        basesort(str, self, sa, n, m);
        calc_rank(str, s1, s2, 0);
        for(int i = 0; (1<<i) < n; i++) {
            for(int j = 0; j < n; j++) {
                s1[j] = rank[j] + 1;
                s2[j] = j + (1<<i) < n ? rank[j + (1<<i)] + 1 : 0;
            }
            basesort(s2, self, rank, n, n);
            basesort(s1, rank, sa,   n, n);
            calc_rank(str, s1, s2, 1);
        }
    }

    void get_height() { //求height
        int j, k = 0;
        height[0] = 0;
        for(int i = 0; i < n; i++) {
            if(!rank[i]) continue;
            if(k) k--;
            j = sa[rank[i] - 1];
            while(str[i+k] == str[j+k] && i+k < n && j+k < n) k++;
            height[rank[i]] = k;
        }
    }

    void import_info(int *str1, int *sa1, int *rank1, int *height1, int *n1, int *m1) {
    //导入各种参数    
        str = str1; sa = sa1; rank = rank1; height = height1; n = *n1; m = *m1;
    }

    void calc() {
        get_sa(); get_height();
    }
} sa_p;

int str[maxn], sa[maxn], rank[maxn], height[maxn], n, m;
int read_in() {
    int i = 0;
    char c;
    while(c = getchar(), c!=EOF && c!='\n')
		str[i++] = (int)c;
    return i;
}
int main() {
    n = read_in(); m = 128;
    sa_p.import_info(str, sa, rank, height, &n, &m);
    sa_p.get_sa();
    for(int i = 0; i < n; i++)
        printf("%d ", sa[i]+1);
    printf("\n");
    return 0;
}
