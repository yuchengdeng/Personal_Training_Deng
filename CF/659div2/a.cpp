#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, a[200];
int s[2][300];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 0; i <= n; i++)
        {
            for(int j = 1; j <= min(a[i], a[i+1]); j++)
                s[i%2][j] = s[(j+1)%2][j];
            for(int j = min(a[i],a[i+1]); j <=max(a[i], a[i+1]); j++)
                s[i%2][j] = (s[(j+1)%2][j] + 1)%26;
            for(int j = 1; j <= max(a[i], a[i+1]); j++)
                printf("%c", s[i%2][j]);
            printf("\n");
        }
    }
    return 0;
}   