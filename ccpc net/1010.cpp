#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t, n, a[50];
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        flag = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(i>1 && a[i]==a[i-1])
            {
                flag = 1;
                break;
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}