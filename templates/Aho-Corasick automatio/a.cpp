//此版本实际上是将trie树变成了trie图,与另一版本只有fail指针构建过程不同
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define maxn 500010
#define maxl 1000010
struct node {
    int fail; //失配指针
    int son[26];//子节点编号
    int ends; //结束标记
} trie[maxn];

int cnt; //当前结点个数
int newnode() { //新节点初始化
    trie[++cnt].fail = 0;
    trie[cnt].ends = 0;
    for(int i = 0; i < 26; i++) 
        trie[cnt].son[i] = -1;
    return cnt;
}
void build(char *s) { //构建trie树
    int len = strlen(s), now = 0;
    newnode();
    for(int i = 0; i < len; i++) {
        if(trie[now].son[s[i]-'a'] == -1) 
            trie[now].son[s[i]-'a'] = newnode();
        now = trie[now].son[s[i]-'a'];
    }
    trie[now].ends++;
}

void get_fail() { //计算失配指针（构建trie图）
    queue<int> que;
    int now, last;
    for(int i = 0; i < 26; i++)
        if(trie[0].son[i]>=0) {
            trie[trie[0].son[i]].fail = 0;
            que.push(trie[0].son[i]);
        }
    while(!que.empty()) {
        now = que.front(); que.pop();
        last = trie[now].fail;
        for(int i = 0; i < 26; i++)
            if (trie[now].son[i] < 0)
                trie[now].son[i] = trie[last].son[i];
            else
            {
                trie[trie[now].son[i]].fail = trie[last].son[i];
                que.push(trie[now].son[i]);
            }    
    }
}

int work(char *s) { //匹配，计算串s中存在的模式串数量
    int len = strlen(s), now = 0, ans = 0;
    for(int i = 0; i < len; i++) {
        now = trie[now].son[s[i]-'a'];
        for(int t = now; t>0&&trie[t].ends>=0; t=trie[t].fail) {
            ans += trie[t].ends;
            trie[t].ends = -trie[t].ends-1;
        }
    }
    return ans;
}

void repair() { //恢复ends
    for(int i = 0; i <= cnt; i++)
        if(trie[i].ends < 0)
            trie[i].ends = -trie[i].ends-1;
}

char str[maxl];
int main() {
    int n,T;
    scanf("%d", &T);
    for(int w = 1; w <= T; w++) {
        cnt = -1;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", str);
            build(str);
        }
        get_fail();
        scanf("%s", str);
        printf("%d\n", work(str));
        //repair(); 
    }
    return 0;
}