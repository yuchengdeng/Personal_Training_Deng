#include <iostream>
using namespace std;
int main()
{
    freopen("c.in", "w", stdout);
    printf("200001\n");
    for(int i = 1; i <= 100000; i++)
        printf("%d %d\n%d %d\n", i, 2*i, i, 2*i+1);
    return 0;
}