#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 200020
void radix(int *str, int *a, int *b, int n, int m) {
    static int count[maxn];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < n;  i++) ++count[str[a[i]]];
    for(int i = 1; i <= m; i++) count[i] += count[i-1];
    for(int i = n-1; i >= 0; --i) b[--count[str[a[i]]]] = a[i];
}

void suffix_array(int *str, int *sa, int n, int m) {
    static int rank[maxn], a[maxn], b[maxn];
    for(int i = 0; i < n; ++i) rank[sa[i]] = rank[sa[i-1]] + (str[sa[i]]!=str[sa[i-1]]);
    for(int i = 0; 1<<i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i] = rank[j] + 1;
            b[j] = j + (1<<i) >= n ? 0 : rank[j+(1 << i)] + 1;
            sa[j] = j;
        }
        radix(b, sa, rank, n, n);
        radix(a, rank, sa, n, n);
        rank[sa[0]] = 0;
        for(int j = 1; j < n; j++) {
            rank[sa[j]] = rank[sa[j-1]] + (a[sa[j-1]] != a[sa[j]] || b[sa[j-1]] != b[sa[j]]);
        }
    }
}

int main() {
    
}