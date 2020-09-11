#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#define maxn 1000000
using namespace std;
string name1, name2;
string s1;
string s2;
int cnt1, cnt2, w1[maxn], w2[maxn], f[2][maxn];

string read(const string name, int *cnt, int *w)    //文件读入及处理
{
    string s;
    int i = -1; w[0] = -1;
    FILE *fp;
    fp = fopen(name.c_str(), "r");
    *cnt = 0;
    s = "";
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        if(c == ' ') continue;
        if(c == '\n')
        {
            if(i >= 0 && i != w[*cnt])
            {
                (*cnt)++;
                w[*cnt] = i;
            }
            continue;
        }
        s.push_back(c);
        i++;
        if(c == '{' || c == '}')
        {
            (*cnt)++;
            w[*cnt] = i;
        }
    }
    if(i != w[*cnt])
    {
        (*cnt)++;
        w[*cnt] = i;
    }
    fclose(fp);
    return s;
}

bool cmp(int x, int y)  //行比较
{
    if(w1[x]-w1[x-1] != w2[y]-w2[y-1])
        return 0;
    for(int i = 1; i <= w1[x]-w1[x-1]; i++)
        if(s1[w1[x-1]+i] != s2[w2[y-1]+i])
            return 0;
    return 1;
}

int main()
{
    cin >> name1;
    cin >> name2;
    memset(w1, 0, sizeof(w1));
    memset(w2, 0, sizeof(w2));
    s1 = read(name1, &cnt1, w1);
    s2 = read(name2, &cnt2, w2);
    for(int i = 0; i <= cnt1; i++)  //求以行为单位的最长公共子序列
        for(int j = 0; j <= cnt2; j++)
            if(i == 0 || j == 0)
                f[i%2][j] = 0;
            else
            {
                if(cmp(i, j) == 1)
                    f[i%2][j] = f[(i-1)%2][j-1] + 1;
                else
                    f[i%2][j] = max(f[(i-1)%2][j], f[i%2][j-1]);
            }
    printf("%d %d %d\n", cnt1, cnt2, f[cnt1%2][cnt2]);
    return 0;
}